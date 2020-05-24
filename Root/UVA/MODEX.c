#include <stdio.h>

long long mod(long long,long long,long long);

int main()
{
    long long n,p,m,i,j;
    scanf("%lld",&i);
    for(j=0; j<i; j++)
    {
        scanf("%lld %lld %lld",&n,&p,&m);
        printf("%lld\n",mod(n,p,m));
    }

    return 0;
}

long long mod(long long n,long long p,long long m)
{
    long long por;
    if(p==0)
        return (1%m);

    else if(p%2 == 0)
    {
        por=mod(n,p/2,m);
        return ((por%m) * (por%m)) % m;
    }

    else
        return ( (n%m) * (mod(n,p-1,m)%m) ) %m;
}
