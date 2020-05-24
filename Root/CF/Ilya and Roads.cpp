#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace  std;

typedef long long ll;
const ll inf = 1e15;
#define SZ 305

ll n, mat[SZ][SZ], dp[SZ][SZ];

ll solve(ll indx, ll k)
{
    if(k <= 0) return 0LL;
    if(indx == n+1) return inf;

    ll &ret = dp[indx][k];
    if(ret != -1) return ret;

    ll i;
    ret = inf;

    for(i=indx; i<=n; i++)
    {
        if(mat[indx][i] == inf) ret = min(ret, solve(i+1, k));
        else ret = min(ret,mat[indx][i] + solve(i+1, k-(i-indx+1)));
    }

    ret = min(ret, solve(indx+1, k));

    return ret;
}

//%I64d
int main()
{
    ll m,i,j,p,k,f,t,cost;

    while(scanf("%I64d %I64d %I64d",&n,&m,&k) == 3)
    {
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                mat[i][j] = inf, dp[i][j] = -1;

        for(i=1; i<=m; i++)
        {
            scanf("%I64d %I64d %I64d", &f, &t, &cost);
            mat[f][t] = min(mat[f][t], cost);
        }

        for(i=1;i<=n;i++)
            for(j=i;j<=n;j++)
                if(mat[i][j] != inf)
                    for(p=i;p<=j;p++)
                            mat[i][p] = min(mat[i][p], mat[i][j]),
                            mat[p][j] = min(mat[p][j], mat[i][j]);

        j = solve(1,k);

        if(j >= inf) printf("-1\n");
        else cout << j << "\n";
    }

    return 0;
}
