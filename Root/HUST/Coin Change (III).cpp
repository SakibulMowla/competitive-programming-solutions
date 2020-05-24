#include "stdio.h"
#include "string.h"
#define SZ 110
#define SZ1 100010

typedef long long ll;
bool dp[SZ1];
ll coin[SZ], used[SZ1] , numb[SZ];

int main()
{
    ll t=0,test,i,j,m,n,cnt;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0; i<n; i++) scanf("%lld",&coin[i]);
        for(i=0; i<n; i++) scanf("%lld",&numb[i]);
        for(i=1; i<=m; i++) dp[i] = 0;
        dp[0] = 1;
        cnt = 0;
        for(i=0; i<n; i++)
        {
            memset(used,0,sizeof(ll)*(m+1));
            for(j=coin[i]; j<=m; j++)
            {
                if(!dp[j] && dp[j-coin[i]] && used[j-coin[i]] < numb[i] )
                {
                    cnt++ , dp[j] = 1 , used[j] = used[j-coin[i]] + 1;
                }
            }
        }
//        k = 0;
//        for(i=1; i<=m; i++) if(dp[i]) k++;
        printf("Case %lld: %lld\n",++t,cnt);
    }

    return 0;
}
