#include "stdio.h"
typedef long long ll;

ll arr[201] , dp[201][21][11] , m;

ll solve(ll indx,ll mod,ll taken)
{
    if(taken == 0)
    {
        if(mod == 0) return 1;
        return 0;
    }
    if(indx < 1) return 0;
    if(dp[indx][mod][taken] != -1) return dp[indx][mod][taken];
    ll i;
    i = (mod + arr[indx]) % m;
    if(i < 0) i = i + m;
    return dp[indx][mod][taken] = solve(indx-1,i,taken-1) + solve(indx-1,mod,taken);
}

int main()
{
    ll t,t1,i,n,q,u,v,w;
    t = 0;
    while(scanf("%lld %lld",&n,&q) == 2 &&(n+q))
    {
        for(i=1;i<=n;i++) scanf("%lld",&arr[i]);
        printf("SET %lld:\n",++t);
        t1 = 0;
        while(q--)
        {
            scanf("%lld %lld",&m,&i);
            for(u=0;u<=n;u++) for(v=0;v<=m;v++) for(w=0;w<=i;w++) dp[u][v][w] = -1;
            printf("QUERY %lld: %lld\n",++t1,solve(n,0,i));
        }
    }

    return 0;
}
