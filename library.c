/*
 * NEON ARCHIVE // Cyberpunk Library Terminal
 * C11 | Persistent binary storage | Windows / Linux / macOS
 *
 * Build:
 *   gcc neon_archive.c -std=c11 -Wall -Wextra -O2 -o neon_archive
 *
 * Run:
 *   Windows: .\neon_archive.exe
 *   Linux/macOS: ./neon_archive
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
static void sleep_ms(unsigned int ms) { Sleep(ms); }
#else
#include <unistd.h>
static void sleep_ms(unsigned int ms) {
    clock_t start = clock();
    clock_t ticks = (clock_t)((double)ms * CLOCKS_PER_SEC / 1000.0);
    while (clock() - start < ticks) {}
}
#endif

#define DB_FILE "neon_archive.db"
#define TITLE_LEN 96
#define AUTHOR_LEN 72
#define MAX_INPUT 256

typedef struct {
    int id;
    char title[TITLE_LEN];
    char author[AUTHOR_LEN];
    int year;
    int total;
    int available;
    unsigned long long scans;
} Book;

static Book *catalog = NULL;
static size_t book_count = 0;
static size_t book_capacity = 0;
static int color_enabled = 1;

/* ---------- Terminal visuals ---------- */

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define CYAN    "\033[96m"
#define MAGENTA "\033[95m"
#define GREEN   "\033[92m"
#define YELLOW  "\033[93m"
#define RED     "\033[91m"
#define BLUE    "\033[94m"
#define WHITE   "\033[97m"

static const char *paint(const char *code) {
    return color_enabled ? code : "";
}

static void clear_screen(void) {
    printf("\033[2J\033[H");
}

static void line(void) {
    printf("%s+-----------------------------------------------------------------------+%s\n",
           paint(CYAN), paint(RESET));
}

static void pause_enter(void) {
    char buf[MAX_INPUT];
    printf("\n%s[ENTER]%s return to command deck...", paint(MAGENTA), paint(RESET));
    (void)fgets(buf, sizeof(buf), stdin);
}

static void boot_animation(void) {
    const char *steps[] = {
        "Mounting archive core",
        "Indexing encrypted shelves",
        "Warming up search engine",
        "Checking local database"
    };
    size_t i;

    clear_screen();
    printf("%s", paint(CYAN));
    printf("  _   _ _____ ___  _   _    _    ____   ____ _   _ _____\n");
    printf(" | \\ | | ____/ _ \\| \\ | |  / \\  |  _ \\ / ___| | | | ____|\n");
    printf(" |  \\| |  _|| | | |  \\| | / _ \\ | |_) | |   | |_| |  _|\n");
    printf(" | |\\  | |__| |_| | |\\  |/ ___ \\|  _ <| |___|  _  | |___\n");
    printf(" |_| \\_|_____\\___/|_| \\_/_/   \\_\\_| \\_\\\\____|_| |_|_____|\n");
    printf("%s\n", paint(RESET));
    printf("%s             THE FUTURE OF KNOWLEDGE IS LOCAL%s\n\n",
           paint(MAGENTA), paint(RESET));

    for (i = 0; i < sizeof(steps) / sizeof(steps[0]); i++) {
        printf("%s[SYS]%s %-32s ", paint(GREEN), paint(RESET), steps[i]);
        fflush(stdout);
        for (int j = 0; j < 18; j++) {
            printf("%s%c%s", paint(CYAN), (j % 3 == 0 ? '#' : '='), paint(RESET));
            fflush(stdout);
            sleep_ms(18);
        }
        printf(" %sOK%s\n", paint(GREEN), paint(RESET));
    }
    sleep_ms(200);
}

/* ---------- Input and memory ---------- */

static void read_line(const char *prompt, char *out, size_t size) {
    size_t len;
    int ch;

    printf("%s", prompt);
    if (!fgets(out, (int)size, stdin)) {
        out[0] = '\0';
        return;
    }

    len = strlen(out);
    if (len > 0 && out[len - 1] == '\n') {
        out[len - 1] = '\0';
    } else {
        while ((ch = getchar()) != '\n' && ch != EOF) {}
    }
}

static int parse_int(const char *s, int *value) {
    char *end;
    long n;

    while (isspace((unsigned char)*s)) s++;
    if (*s == '\0') return 0;

    n = strtol(s, &end, 10);
    while (isspace((unsigned char)*end)) end++;

    if (*end != '\0' || n < INT_MIN || n > INT_MAX) return 0;
    *value = (int)n;
    return 1;
}

static int ask_int(const char *prompt, int min, int max) {
    char buf[MAX_INPUT];
    int value;

    for (;;) {
        read_line(prompt, buf, sizeof(buf));
        if (parse_int(buf, &value) && value >= min && value <= max)
            return value;
        printf("%s[ERR]%s Enter a whole number from %d to %d.\n",
               paint(RED), paint(RESET), min, max);
    }
}

static int reserve_slot(void) {
    Book *tmp;
    size_t new_capacity;

    if (book_count < book_capacity) return 1;

    new_capacity = book_capacity == 0 ? 8 : book_capacity * 2;
    if (new_capacity > SIZE_MAX / sizeof(Book)) {
        printf("%s[ERR]%s Catalog capacity limit reached.\n", paint(RED), paint(RESET));
        return 0;
    }

    tmp = (Book *)realloc(catalog, new_capacity * sizeof(Book));
    if (!tmp) {
        printf("%s[ERR]%s Memory allocation failed.\n", paint(RED), paint(RESET));
        return 0;
    }

    catalog = tmp;
    book_capacity = new_capacity;
    return 1;
}

static int find_index(int id) {
    size_t i;
    for (i = 0; i < book_count; i++)
        if (catalog[i].id == id) return (int)i;
    return -1;
}

/* ---------- Database ---------- */

static int save_database(void) {
    FILE *fp = fopen(DB_FILE, "wb");
    unsigned int version = 1;
    unsigned long long n = (unsigned long long)book_count;

    if (!fp) {
        printf("%s[ERR]%s Could not open database for writing.\n", paint(RED), paint(RESET));
        return 0;
    }

    if (fwrite(&version, sizeof(version), 1, fp) != 1 ||
        fwrite(&n, sizeof(n), 1, fp) != 1 ||
        (book_count && fwrite(catalog, sizeof(Book), book_count, fp) != book_count)) {
        fclose(fp);
        printf("%s[ERR]%s Database write failed.\n", paint(RED), paint(RESET));
        return 0;
    }

    if (fclose(fp) != 0) {
        printf("%s[ERR]%s Database close failed.\n", paint(RED), paint(RESET));
        return 0;
    }
    return 1;
}

static void load_database(void) {
    FILE *fp = fopen(DB_FILE, "rb");
    unsigned int version;
    unsigned long long n;

    if (!fp) return;

    if (fread(&version, sizeof(version), 1, fp) != 1 ||
        fread(&n, sizeof(n), 1, fp) != 1 ||
        version != 1 || n > 100000ULL) {
        printf("%s[WARN]%s Database invalid or unsupported; starting empty.\n",
               paint(YELLOW), paint(RESET));
        fclose(fp);
        return;
    }

    if (n > 0) {
        catalog = (Book *)malloc((size_t)n * sizeof(Book));
        if (!catalog) {
            printf("%s[ERR]%s Could not allocate database memory.\n", paint(RED), paint(RESET));
            fclose(fp);
            return;
        }
        book_capacity = (size_t)n;

        if (fread(catalog, sizeof(Book), (size_t)n, fp) != (size_t)n) {
            printf("%s[WARN]%s Database is incomplete; ignoring it.\n",
                   paint(YELLOW), paint(RESET));
            free(catalog);
            catalog = NULL;
            book_capacity = 0;
            fclose(fp);
            return;
        }
        book_count = (size_t)n;
    }

    fclose(fp);
}

/* ---------- Search helpers ---------- */

static int contains_ci(const char *text, const char *query) {
    size_t i, j;
    size_t n = strlen(text), m = strlen(query);

    if (m == 0) return 1;
    if (m > n) return 0;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (tolower((unsigned char)text[i + j]) !=
                tolower((unsigned char)query[j])) break;
        }
        if (j == m) return 1;
    }
    return 0;
}

static void print_book(const Book *b) {
    printf("\n%s+-- BOOK RECORD --------------------------------------------------------+%s\n",
           paint(MAGENTA), paint(RESET));
    printf("  ID:          %s#%d%s\n", paint(CYAN), b->id, paint(RESET));
    printf("  Title:       %s\n", b->title);
    printf("  Author:      %s\n", b->author);
    printf("  Year:        %d\n", b->year);
    printf("  Copies:      %d total | %s%d available%s\n",
           b->total, paint(GREEN), b->available, paint(RESET));
    printf("  Scan count:  %llu\n", b->scans);
    printf("%s+----------------------------------------------------------------------+%s\n",
           paint(MAGENTA), paint(RESET));
}

static void show_catalog(void) {
    size_t i;

    clear_screen();
    line();
    printf("%s                         ARCHIVE CATALOG%s\n", paint(BOLD), paint(RESET));
    line();

    if (book_count == 0) {
        printf("\n  %sThe shelves are empty. Add the first record.%s\n",
               paint(YELLOW), paint(RESET));
    } else {
        printf("  %-6s %-29s %-20s %4s  %s\n",
               "ID", "TITLE", "AUTHOR", "YEAR", "STOCK");
        printf("  ---------------------------------------------------------------------\n");
        for (i = 0; i < book_count; i++) {
            printf("  %-6d %-29.29s %-20.20s %4d  %d/%d\n",
                   catalog[i].id, catalog[i].title, catalog[i].author,
                   catalog[i].year, catalog[i].available, catalog[i].total);
        }
    }
    line();
    pause_enter();
}

static void add_book(void) {
    Book b;

    clear_screen();
    printf("%s[ NEW ARCHIVE RECORD ]%s\n\n", paint(CYAN), paint(RESET));

    b.id = ask_int("Unique numeric ID: ", 1, INT_MAX);
    if (find_index(b.id) >= 0) {
        printf("%s[ERR]%s That ID already exists.\n", paint(RED), paint(RESET));
        pause_enter();
        return;
    }

    read_line("Book title: ", b.title, sizeof(b.title));
    read_line("Author name: ", b.author, sizeof(b.author));
    if (!b.title[0] || !b.author[0]) {
        printf("%s[ERR]%s Title and author cannot be empty.\n", paint(RED), paint(RESET));
        pause_enter();
        return;
    }

    b.year = ask_int("Publication year (1-9999): ", 1, 9999);
    b.total = ask_int("Number of copies (1-100000): ", 1, 100000);
    b.available = b.total;
    b.scans = 0;

    if (!reserve_slot()) {
        pause_enter();
        return;
    }

    catalog[book_count++] = b;
    if (save_database())
        printf("\n%s[OK]%s Record committed to local archive.\n", paint(GREEN), paint(RESET));
    pause_enter();
}

static void search_books(void) {
    char query[MAX_INPUT];
    int mode, found = 0;
    size_t i;

    clear_screen();
    printf("%s[ DEEP SEARCH ]%s\n\n", paint(CYAN), paint(RESET));
    printf("  1. Search ID\n  2. Search title\n  3. Search author\n\n");
    mode = ask_int("Select search mode: ", 1, 3);

    if (mode == 1) {
        int id = ask_int("ID: ", 1, INT_MAX);
        int idx = find_index(id);
        if (idx >= 0) {
            catalog[idx].scans++;
            print_book(&catalog[idx]);
            save_database();
        } else {
            printf("%s[NO MATCH]%s No record with that ID.\n", paint(YELLOW), paint(RESET));
        }
        pause_enter();
        return;
    }

    read_line("Search phrase: ", query, sizeof(query));
    if (!query[0]) {
        printf("Search phrase cannot be empty.\n");
        pause_enter();
        return;
    }

    for (i = 0; i < book_count; i++) {
        const char *field = mode == 2 ? catalog[i].title : catalog[i].author;
        if (contains_ci(field, query)) {
            catalog[i].scans++;
            print_book(&catalog[i]);
            found = 1;
        }
    }

    if (!found)
        printf("%s[NO MATCH]%s No records matched that phrase.\n", paint(YELLOW), paint(RESET));
    else
        save_database();

    pause_enter();
}

static void edit_book(void) {
    int id, idx;
    char buf[MAX_INPUT];
    Book old;

    clear_screen();
    printf("%s[ RECORD MODIFICATION ]%s\n\n", paint(CYAN), paint(RESET));
    id = ask_int("Book ID: ", 1, INT_MAX);
    idx = find_index(id);

    if (idx < 0) {
        printf("%s[ERR]%s Record not found.\n", paint(RED), paint(RESET));
        pause_enter();
        return;
    }

    old = catalog[idx];
    print_book(&catalog[idx]);
    printf("\nLeave any field blank to keep it unchanged.\n");

    read_line("New title: ", buf, sizeof(buf));
    if (buf[0]) {
        if (strlen(buf) >= TITLE_LEN) {
            printf("Title too long; edit cancelled.\n");
            pause_enter();
            return;
        }
        strcpy(catalog[idx].title, buf);
    }

    read_line("New author: ", buf, sizeof(buf));
    if (buf[0]) {
        if (strlen(buf) >= AUTHOR_LEN) {
            printf("Author name too long; edit cancelled.\n");
            catalog[idx] = old;
            pause_enter();
            return;
        }
        strcpy(catalog[idx].author, buf);
    }

    read_line("New publication year: ", buf, sizeof(buf));
    if (buf[0]) {
        int year;
        if (!parse_int(buf, &year) || year < 1 || year > 9999) {
            printf("Invalid year; edit cancelled.\n");
            catalog[idx] = old;
            pause_enter();
            return;
        }
        catalog[idx].year = year;
    }

    read_line("New total copies: ", buf, sizeof(buf));
    if (buf[0]) {
        int total;
        int issued = old.total - old.available;
        if (!parse_int(buf, &total) || total < 1 || total < issued) {
            printf("Invalid total or fewer copies than currently issued; edit cancelled.\n");
            catalog[idx] = old;
            pause_enter();
            return;
        }
        catalog[idx].total = total;
        catalog[idx].available = total - issued;
    }

    if (save_database()) {
        printf("%s[OK]%s Record updated.\n", paint(GREEN), paint(RESET));
    } else {
        catalog[idx] = old;
    }
    pause_enter();
}

static void delete_book(void) {
    int id, idx;
    char confirm[16];

    clear_screen();
    printf("%s[ PURGE RECORD ]%s\n\n", paint(RED), paint(RESET));
    id = ask_int("Book ID to delete: ", 1, INT_MAX);
    idx = find_index(id);

    if (idx < 0) {
        printf("Record not found.\n");
        pause_enter();
        return;
    }
    if (catalog[idx].available != catalog[idx].total) {
        printf("%s[BLOCKED]%s Return all issued copies before deleting this record.\n",
               paint(RED), paint(RESET));
        pause_enter();
        return;
    }

    print_book(&catalog[idx]);
    read_line("Type DELETE to confirm: ", confirm, sizeof(confirm));
    if (strcmp(confirm, "DELETE") != 0) {
        printf("Purge cancelled.\n");
        pause_enter();
        return;
    }

    {
        Book removed = catalog[idx];
        size_t i;
        for (i = (size_t)idx; i + 1 < book_count; i++)
            catalog[i] = catalog[i + 1];
        book_count--;

        if (save_database()) {
            printf("%s[OK]%s Record purged.\n", paint(GREEN), paint(RESET));
        } else {
            if (reserve_slot()) {
                for (i = book_count; i > (size_t)idx; i--)
                    catalog[i] = catalog[i - 1];
                catalog[idx] = removed;
                book_count++;
            }
            printf("%s[ERR]%s Save failed; attempted rollback.\n", paint(RED), paint(RESET));
        }
    }
    pause_enter();
}

static void change_stock(int issue) {
    int id, idx;

    clear_screen();
    printf("%s[%s COPY ]%s\n\n", paint(CYAN), issue ? "ISSUE" : "RETURN", paint(RESET));
    id = ask_int("Book ID: ", 1, INT_MAX);
    idx = find_index(id);

    if (idx < 0) {
        printf("%s[ERR]%s Record not found.\n", paint(RED), paint(RESET));
        pause_enter();
        return;
    }

    if (issue && catalog[idx].available == 0) {
        printf("%s[OUT OF STOCK]%s No copies available.\n", paint(RED), paint(RESET));
        pause_enter();
        return;
    }
    if (!issue && catalog[idx].available == catalog[idx].total) {
        printf("%s[INVALID]%s All copies are already in stock.\n", paint(YELLOW), paint(RESET));
        pause_enter();
        return;
    }

    if (issue) catalog[idx].available--;
    else catalog[idx].available++;

    if (save_database()) {
        printf("\n%s[TRANSACTION OK]%s %s: %s\n",
               paint(GREEN), paint(RESET), issue ? "Issued" : "Returned",
               catalog[idx].title);
        printf("Stock now: %d available / %d total\n",
               catalog[idx].available, catalog[idx].total);
    } else {
        if (issue) catalog[idx].available++;
        else catalog[idx].available--;
    }
    pause_enter();
}

static void sort_catalog(void) {
    int mode;
    size_t i, j;

    clear_screen();
    printf("%s[ SORT ENGINE ]%s\n\n", paint(CYAN), paint(RESET));
    printf("  1. Alphabetical title\n  2. Publication year (oldest first)\n  3. Most scanned\n\n");
    mode = ask_int("Sort mode: ", 1, 3);

    for (i = 0; i < book_count; i++) {
        for (j = 0; j + 1 < book_count - i; j++) {
            int swap = 0;
            if (mode == 1)
                swap = strcmp(catalog[j].title, catalog[j + 1].title) > 0;
            else if (mode == 2)
                swap = catalog[j].year > catalog[j + 1].year;
            else
                swap = catalog[j].scans < catalog[j + 1].scans;

            if (swap) {
                Book tmp = catalog[j];
                catalog[j] = catalog[j + 1];
                catalog[j + 1] = tmp;
            }
        }
    }

    if (save_database())
        printf("\n%s[OK]%s Catalog order updated and saved.\n", paint(GREEN), paint(RESET));
    show_catalog();
}

static void statistics(void) {
    size_t i;
    unsigned long long copies = 0, available = 0, scans = 0;
    size_t low_stock = 0;
    const Book *popular = NULL;

    for (i = 0; i < book_count; i++) {
        copies += (unsigned long long)catalog[i].total;
        available += (unsigned long long)catalog[i].available;
        scans += catalog[i].scans;
        if (catalog[i].available == 0) low_stock++;
        if (!popular || catalog[i].scans > popular->scans) popular = &catalog[i];
    }

    clear_screen();
    line();
    printf("%s                         SYSTEM INTELLIGENCE%s\n", paint(BOLD), paint(RESET));
    line();
    printf("\n  Unique titles       : %s%llu%s\n", paint(CYAN),
           (unsigned long long)book_count, paint(RESET));
    printf("  Physical copies     : %llu\n", copies);
    printf("  Available now       : %s%llu%s\n", paint(GREEN), available, paint(RESET));
    printf("  Currently issued    : %llu\n", copies - available);
    printf("  Out-of-stock titles : %s%zu%s\n", paint(YELLOW), low_stock, paint(RESET));
    printf("  Search scan events  : %llu\n", scans);

    if (popular) {
        printf("\n  MOST SCANNED RECORD\n");
        printf("  %-30.30s | %llu scans\n", popular->title, popular->scans);
    }
    line();
    pause_enter();
}

static void dashboard(void) {
    size_t i;
    unsigned long long total = 0, available = 0;

    for (i = 0; i < book_count; i++) {
        total += (unsigned long long)catalog[i].total;
        available += (unsigned long long)catalog[i].available;
    }

    clear_screen();
    printf("%s", paint(CYAN));
    printf("  _   _ _____ ___  _   _    _    ____   ____ _   _ _____\n");
    printf(" | \\ | | ____/ _ \\| \\ | |  / \\  |  _ \\ / ___| | | | ____|\n");
    printf(" |  \\| |  _|| | | |  \\| | / _ \\ | |_) | |   | |_| |  _|\n");
    printf(" | |\\  | |__| |_| | |\\  |/ ___ \\|  _ <| |___|  _  | |___\n");
    printf(" |_| \\_|_____\\___/|_| \\_/_/   \\_\\_| \\_\\\\____|_| |_|_____|\n");
    printf("%s\n", paint(RESET));
    line();
    printf("  %sARCHIVE STATUS%s   [%sONLINE%s]     Local persistence: [%sACTIVE%s]\n",
           paint(BOLD), paint(RESET), paint(GREEN), paint(RESET), paint(GREEN), paint(RESET));
    printf("  Unique titles: %-8zu Total copies: %-8llu Available: %llu\n",
           book_count, total, available);
    line();
    printf("\n  %sCOMMAND DECK%s\n", paint(MAGENTA), paint(RESET));
    printf("  [1] Add record       [2] Browse catalog    [3] Deep search\n");
    printf("  [4] Edit record      [5] Purge record      [6] Issue copy\n");
    printf("  [7] Return copy      [8] Sort engine       [9] Intelligence\n");
    printf("  [0] Save and exit\n\n");
}

int main(void) {
    int choice;

    boot_animation();
    load_database();

    for (;;) {
        dashboard();
        choice = ask_int("  ARCHIVE:// ", 0, 9);

        switch (choice) {
            case 1: add_book(); break;
            case 2: show_catalog(); break;
            case 3: search_books(); break;
            case 4: edit_book(); break;
            case 5: delete_book(); break;
            case 6: change_stock(1); break;
            case 7: change_stock(0); break;
            case 8: sort_catalog(); break;
            case 9: statistics(); break;
            case 0:
                if (save_database())
                    printf("\n%s[SYS]%s Archive saved. Session terminated.\n",
                           paint(GREEN), paint(RESET));
                free(catalog);
                return 0;
            default:
                break;
        }
    }
}