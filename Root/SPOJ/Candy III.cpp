#include "stdio.h"

int main()
{
    long long t,i,j,k,n,m;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        k = n;
        j = 0ll;
        while(n--)
        {
            scanf("%lld",&i);
            j+=i;
            j %= k;
        }
        if(k != 0 && j % k == 0) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
