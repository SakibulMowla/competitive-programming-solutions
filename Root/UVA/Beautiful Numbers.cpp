#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
const ll mod = 1000000007LL;

ll dp[110][12][(1<<10)+2]; //prev, mask(color), flag(valid number)
int n, m, k;

ll solve(int indx, int prev, int mask, int l)
{
//    printf("%d %d %d\n",indx, prev, mask);
    if(indx == m)
    {
        if(!mask)
        {
//            printf("len = %d\n",l);
            return 1LL;
        }
        return 0LL;
    }

    ll &ret = dp[indx][prev][mask];
    if(ret != -1) return ret;

    int i;
    ret = 0LL;

    if(mask == k)
    {
        for(i=0; i<n; i++)
        {
            if(i == 0) ret = solve(indx+1, i, k, 0) % mod;
            else ret = ( ret + solve(indx+1, i, k&~(1<<i), l+1) ) % mod;
        }

        return ret;
    }

    if(prev+1 < n)
    {
        ret = solve(indx+1, prev+1, mask&~(1<<(prev+1)), l+1) % mod;
    }

    if(prev-1 > -1)
        ret = (ret + solve(indx+1, prev-1, mask&~(1<<(prev-1)), l+1) ) % mod;


    return ret;
}


int main()
{
    int t, i, j, l;
    ll ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        if(m == 0)
        {
            printf("0\n");
            continue;
        }

        ans = 0LL;
        k = (1<<n)-1;

        for(i=0;i<=m;i++)
            for(j=0;j<11;j++)
                for(l=0;l<=k;l++)
                    dp[i][j][l] = -1;
//        memset(dp, -1, sizeof(dp));

        for(i=0; i<n; i++)
        {
            if(i == 0) ans = (ans + solve(1, i, k, 0) ) % mod;
            else ans = ( ans + solve(1, i, k&~(1<<i), 1) ) % mod;
        }

        printf("%lld\n",ans);
    }

    return 0;
}
