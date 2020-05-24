#include "iostream"
#include "vector"
#include "stdio.h"
#include "string.h"
using namespace std;

#define SZ 15

vector <int> adj[SZ+2];
int n, m;
int connect[SZ+2][(1<<SZ)+2];
int col[(1<<SZ)+2];
int dp[(1<<SZ)+2];

void dfs(int u, int mask)
{
    connect[u][mask] = 1;
    col[mask] = 1;

    int i, j, k;
    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(connect[j][mask|(1<<j)] == 0)
        {
            dfs(j, mask|(1<<j));
        }
    }

    return;
}



int solve(int mask)
{
    if(!mask)
        return 0;

    int &ret = dp[mask];
    if(ret != -1)
        return ret;

    int i;
    ret = 20;

    for(i=mask; i>=0;)
    {
        if(col[i] == 1)
            ret = min(ret, 1+ solve(mask ^ i));
        i--;
        if(i >= 0)
            i &= mask;
    }

    return ret;
}


int main()
{
    int test=0, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<=n; i++)
            adj[i].clear(), memset(connect[i], 0, sizeof(connect[i]));

        k = 1<<n;

        for(i=0; i<k; i++)
            dp[i] = -1, col[i] = 0;

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            j--,k--;
            adj[j].push_back(k);
        }

        for(i=0; i<n; i++)
        {
            dfs(i, 1<<i);
        }

        printf("Case %d: %d\n",++test,solve((1<<n)-1));
    }

    return 0;
}
