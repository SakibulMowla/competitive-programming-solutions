#include "stdio.h"

typedef long long ll;

int main()
{
    ll i,j,k,n,m,t;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        k = 0ll;
        while(n)
        {
            k += (n/5ll);
            n /= 5ll;
        }
        printf("%lld\n",k);
    }
    return 0;
}
