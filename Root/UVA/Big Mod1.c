#include <stdio.h>
#include <math.h>

long long mod(long long b,long long p,long long m);
long long sqr(long long i);

int main()
{
    long long int b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3)
        printf("%lld\n",mod(b,p,m));

    return 0;
}

long long sqr(long long i)
{
    return i*i;
}

long long mod(long long b,long long p,long long m)
{
    if (p==0)
        return (1%m);

    else if (p%2 == 0)
    return sqr( mod (b,p/2,m)) % m;

    else
    return ((b % m) * mod( b,p-1,m)) % m;
}
