#include "stdio.h"
#include "string.h"
#include "vector"
#define SZ 1010

int par[SZ];
bool col[SZ];
std::vector <int> adj[SZ];

bool dfs(int u)
{
    if(col[u]) return false;

    int i, k, v;
    k = adj[u].size();

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if(!col[v])
        {
            col[v] = 1;
            if(par[v] == -1 || dfs(par[v]))
            {
                par[v] = u;
                return true;
            }
        }
    }

    return false;
}

int bpm(int n)
{
    int i, ret = 0;

    memset(par, -1, sizeof(int)*(n+2));

    for(i=1;i<=n;i++)
    {
        memset(col,0,sizeof(bool)*(n+2));
        if(dfs(i)) ret++;
    }

    return ret;
}

int main()
{
    int t=0, test, i, j, k, n, m;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<=n;i++) adj[i].clear();

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        k = bpm(n);
        k = (n - k) + k/2;

        printf("Case %d: %d\n",++t, k);
    }
}
