#include "stdio.h"
#include "string.h"
#include "vector"
#define SZ 201

int par[SZ], a[101], b[101];
bool col[SZ];
std::vector <int> adj[101];

bool dfs(int u)
{
    if(col[u]) return false;

    int i, k, v;
    k = adj[u].size();

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if(col[v] == 0)
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

    memset(par, -1, sizeof(par));

    for(i=1;i<=n;i++)
    {
        memset(col, 0, sizeof(col));
        if(dfs(i)) ret++;
    }

    return ret;
}

int main()
{
    int t=0, test, i, j, n, m;

    scanf("%d", &test);

    while(test--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&a[i]) , adj[i].clear();

        scanf("%d",&m);
        for(i=1;i<=m;i++) scanf("%d",&b[i]);

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if( !(b[j] % a[i]) )
                    adj[i].push_back(j+100);

        printf("Case %d: %d\n",++t,bpm(n));
    }

    return 0;
}
