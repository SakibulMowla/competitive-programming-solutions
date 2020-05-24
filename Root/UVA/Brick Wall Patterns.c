//Working 99.99%
#include<stdio.h>

unsigned long long fibo(int n);

int main()
{
    int i;
    while((scanf("%d",&i))==1)
    {
        if(i==0)
            break;
        printf("%llu\n",fibo(i));
    }

    return 0;
}

unsigned long long fibo(int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    unsigned long long d=fibo(n-1)+fibo(n-2);
    return d;
}

