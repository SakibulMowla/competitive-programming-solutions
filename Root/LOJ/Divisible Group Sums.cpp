#include "stdio.h"
#define SZ 210
#define SZ1 15
#define SZ2 25

typedef long long ll;

ll n , m , d , arr[SZ] , dp[SZ][SZ1][SZ2];

ll solve(ll indx,ll taken,ll mod)
{
    if(taken == m)
    {
        if(mod == 0) return 1ll;
        return 0ll;
    }
    if(indx == n) return 0ll;
    ll &ret = dp[indx][taken][mod];
    if(ret != -1) return ret;
    ll k;
    k = (mod + arr[indx]) % d;
    if(k < 0) k += d;
    ret = solve(indx+1,taken+1,k) + solve(indx+1,taken,mod);
    return ret;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll q,i,j,k,test,t=0;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=0;i<n;i++) scanf("%lld",&arr[i]);
        printf("Case %lld:\n",++t);
        while(q--)
        {
            scanf("%lld %lld",&d,&m);
            for(i=0;i<=n;i++) for(j=0;j<=m;j++) for(k=0;k<=d;k++) dp[i][j][k] = -1;
            printf("%lld\n",solve(0,0,0));
        }
    }

    return 0;
}
