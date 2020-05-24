#include <stdio.h>
#include <math.h>

typedef long long LL;

const LL m = 1000000007;

LL sqr(LL n)
{
    return n*n;
}

LL power(LL base,LL n)
{
    if(n == 0)
        return (1%m);

    else if( n%2 == 0 )
        return sqr( power(base,n/2) ) % m;

    else
        return ( (base % m) * power(base , n-1) ) % m;
}

int main()
{
    LL t = 0,test,n,res;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        res = (n * power(2,n-1)) % m;
        printf("Case #%lld: %lld\n",++t,res);
    }

    return 0;
}
