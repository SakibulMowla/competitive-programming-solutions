#include "stdio.h"
#include "string.h"
#define SZ 210

typedef long long ll;

ll coin[] = {1, 2, 5, 10, 20, 50, 100, 200};
ll dp[SZ];

int main()
{
    ll i,j,k,n;
    dp[0] = 1LL;
    for(i=0;i<8;i++)
        for(j=coin[i];j<=200;j++)
            dp[j] += dp[j-coin[i]];
    printf("%lld\n",dp[200]);

    return 0;
}
