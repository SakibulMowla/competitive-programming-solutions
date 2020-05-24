#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "vector"
#define SZ 105

int par[SZ];
bool col[SZ];
std::vector <int> adj[SZ];

struct data
{
    int h, a, d;
};

data arr[SZ];

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

int bpm(int n,int m)
{
    int i, ret = 0;

    memset(par, -1, sizeof(int)*(m+n));

    for(i=0;i<n;i++)
    {
        memset(col, 0, sizeof(bool)*(m+n));
        if(dfs(i)) ret++;
    }

    return ret;
}

int main()
{
    int t=0, test, n, m, i , j;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n+m;i++)
            scanf("%d %d %d",&arr[i].h ,&arr[i].a ,&arr[i].d ), adj[i].clear();

        for(i=0;i<n;i++)
            for(j=n;j<n+m;j++)
            {
                if( abs(arr[i].h-arr[j].h) <= 12 && abs(arr[i].a-arr[j].a) <= 5 && arr[i].d == arr[j].d )
                    adj[i].push_back(j);
            }
        printf("Case %d: %d\n",++t, bpm(n,m));
    }
}
