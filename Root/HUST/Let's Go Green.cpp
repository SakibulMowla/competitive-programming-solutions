#include "bits/stdc++.h"

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

#define X first
#define Y second

typedef pair<ll,ll> pii;

#define SZ 100010

vector < pii > adj[SZ];

int res;

int leaf(int u, int par)
{
    int i, j, k;
    k = sz(adj[u]);
    for(i=0; i<k; i++)
    {
        j = adj[u][i].X;
        if(j == par) continue;
        return leaf(j, u);
    }
    return u;
}

int dfs(int u,int par,int flow,int notun)
{
    printf("u = %d\n",u);
    int i, j, k, v, tmp, cst;
    k = sz(adj[u]);
    tmp = 0;
    flow += notun;
    for(i=0; i<k; i++)
    {
        v = adj[u][i].X;
        if(v == par) continue;
        cst = adj[u][i].Y;
        if(cst <= flow)
        {
            flow -= cst;
            dfs(v, u, cst, 0);
        }
        else
        {
            res += cst - flow;
            flow = 0;
            flow += dfs(v, u, cst, cst-flow);
        }
    }
    if(notun)
        return flow <= notun ? flow : notun;
    return 0;
}

int main()
{
    int t, test=0, n, i, j, k, l;

    scanf("%d",&t);
    while(t--)
    {
        res = 0;
        scanf("%d",&n);
        for(i=0; i<=n; i++)
            adj[i].clear();
        for(i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j].push_back(MP(k, l));
            adj[k].push_back(MP(j, l));
        }
        printf("leaf = %d\n",leaf(1,-1));
        dfs( leaf(1, -1), -1, 0, 0 );
        printf("Case #%d: %d\n",++test,res);
    }

    return 0;
}
