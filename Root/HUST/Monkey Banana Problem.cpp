#include "stdio.h"
#include "string.h"
#define SZ 210
typedef long long ll;
template <class T> T max(T a,T b) { return a> b ? a : b; }
ll arr[SZ][SZ] , dp[SZ][SZ];

int main()
{
    ll i,j,k,n,m,t,test;
    t = 0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                scanf("%lld",&arr[i][j]);
//        printf("sesh\n");
        for(i=n+1,k=1;i<=2*n-1;i++,k++)
            for(j=1;j<=n-k;j++)
                scanf("%lld",&arr[i][j]);
//        printf("sesh\n");
        for(i=1;i<=n;i++)
            for(j=1;j<=i;j++)
                dp[i][j] = arr[i][j] + max(dp[i-1][j],dp[i-1][j-1]);
        for(i=n+1,k=1;i<=2*n-1;i++,k++)
            for(j=1;j<=n-k;j++)
                dp[i][j] = arr[i][j] + max(dp[i-1][j],dp[i-1][j+1]);
        printf("Case %lld: %lld\n",++t,dp[2*n-1][1]);
    }

    return 0;
}
