#include "stdio.h"
#include "vector"
#include "iostream"

using namespace std;

#define sz(a) (int)a.size()
#define SZ 100010

vector <int> adj[SZ];
bool col[SZ];
int val[SZ], dist[SZ], in[SZ];

int dfs(int u)
{
//    printf("u = %d\n",u);

    if(col[u])
        return dist[u];

    col[u] = 1;

    int i, j, k;

    k = sz(adj[u]);
    dist[u] = val[u];

    int ans = -1e9, f=0;

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
//        printf("j = %d\n",j);
        f = 1;

        if(col[j])
            ans = max(ans, dist[j]);
        else
            ans = max(ans, dfs(j));
    }

    if(f)
        dist[u] += ans;

    return dist[u];
}

int main()
{
    int n, m, i, j, k;

    while(scanf("%d %d",&n,&m) == 2)
    {
        for(i=1; i<=n; i++)
            adj[i].clear(), col[i] = 0, dist[i] = 0, in[i] = 0, scanf("%d",&val[i]);

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            in[k]++;
        }

        k = -1e9;

        for(i=1; i<=n; i++)
            if(in[i] == 0)
                /*printf("i=%d\n",i),*/k = max(k, dfs(i));

        printf("%d\n",k);
    }

    return 0;
}
