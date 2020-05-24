#include "stdio.h"
#define SZ 55

typedef long long ll;
const ll mod = 100000007ll;

ll coin[SZ] , numb[SZ] , dp[1010];

int main()
{
    ll t=0,test,n,i,j,k,l,tmp;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0; i<n; i++) scanf("%lld",&coin[i]);
        for(i=0; i<n; i++) scanf("%lld",&numb[i]);
        for(i=1; i<=k; i++) dp[i] = 0;
        dp[0] = 1;
        for(i=0; i<n; i++)
            for(j=k; j>=0; j--)
            {
                tmp = j;
                for(l=0; l<numb[i]; l++)
                {
                    tmp += coin[i];
                    if(tmp > k) break;
                    dp[tmp] = (dp[tmp] + dp[j]) % mod;
//                    if(i == 0) printf("dp[%lld] = %lld\n",tmp,dp[tmp]);
                }
            }
        printf("Case %lld: %lld\n",++t,dp[k]);
    }

    return 0;
}
