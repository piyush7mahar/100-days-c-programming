#include<stdio.h>
long long factorial(int n);
long long permutation(int n,int r);

int main()
{
    int number;
    printf("ENTER ANY NUMBER=");
    scanf("%d",&number);
    
    int r;
    printf("ENTER r=");
    scanf("%d",&r);
    
    long long p;
    p= permutation(number,r);
    printf("PERMUTATION IS=%lld",p);
    
}
long long factorial(int n)
{
    int i,f=1;
    
    for(i=n;i>=1;i--)
    {
        f=f*i;
    }
    
    return f;
}
long long permutation(int n,int r)
{
    int a=n-r;
    int b,c;
    b=factorial(a);
    c=factorial(n);

    int per;
    per=c/b;

    return per;

}

