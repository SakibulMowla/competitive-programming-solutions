#include "bits/stdc++.h"
using namespace std;

#define SZ 16

int dp[1<<SZ];
bool col[SZ][1<<SZ];
bool conn[1<<SZ];
int n;
vector <int> adj[SZ];

void dfs(int u,int mask)
{
//    printf("u = %d\n",u);
    col[u][mask] = 1;
    conn[mask] = 1;

    int i, j, k;
    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j][ mask|(1<<j) ] == 0)
        {
            dfs(j, mask|(1<<j));
        }
    }

    return ;
}

int solve(int mask)
{
//    printf("yes\n");
    if(!mask) return 0;

    int &ret = dp[mask];
    if(ret != -1) return ret;

    ret = 20;

    int i;

    for(i=mask; i>=0 ; )
    {
        if(conn[i])
            ret = min(ret, solve(mask^i) + 1);
        i--;
        if(i >= 0)
            i &= mask;
    }

    return ret;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int test = 0, t, m, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<n; i++)
        {
            adj[i].clear();
            memset(col[i], 0, sizeof(col[i]));
        }

        k = 1<<n;

        for(i=0; i<k; i++)
            dp[i] = -1, conn[i] = 0;

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

        printf("Case %d: %d\n", ++test, solve( (1<<n) - 1 ) );
    }

    return 0;
}
