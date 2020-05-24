#include <stdio.h>
#include <ctype.h>
#include <string.h>

void bangla (long long int n)
{
    long long int d;
    if (n>=10000000)
    {
        d = n/10000000;
        printf(" %lld kuti",d);
        n = n%10000000;
    }
    if (n>=100000)
    {
        d = n/100000;
        printf(" %lld lakh",d);
        n = n%100000;
    }
    if (n>=1000)
    {
        d = n/1000;
        printf(" %lld hajar",d);
        n = n%1000;
    }
    if (n>=100)
    {
        d = n/100;
        printf(" %lld shata",d);
        n = n%100;
    }
    if (n!=0) printf(" %lld",n);
}

int main()
{
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
    long long int n;
    int test=0;
    while (scanf("%lld",&n) == 1)
    {
        printf("%4d.",++test);
        if (n==0) printf(" 0");
        else if (n<=999999999) bangla(n);
        else
        {
            bangla(n/10000000);
            printf(" kuti");
            bangla(n%10000000);
        }
        printf("\n");
    }
    return 0;
}


