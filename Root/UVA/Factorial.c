#include<stdio.h>
long long int fac(int n);

int main()
{
    int i;
    long long int d;
    while((scanf("%d",&i))==1)
    {d=fac(i);
    if(d<10000)
        printf("Underflow!\n");
    else if(d>6227020800)
        printf("Overflow!\n");
    else
        printf("%lld\n",d);}

    return 0;
}

long long int fac(int n)
{
    int d;
    if(n<=1)
        return 1;
    d=n*fac(n-1);
    return d;
}
