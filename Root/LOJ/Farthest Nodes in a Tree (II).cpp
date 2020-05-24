#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 30010
#define sz(a) ((int)a.size())
#define MP(a,b) make_pair(a,b)
#define X first
#define Y second

typedef pair<int , int> pii;

int dp[SZ][2];
bool col[SZ];
vector <pii> adj[SZ];

pii dfs(int u)
{
    col[u] = 1;
    pii ret = MP(u, 0);

    int i, v, c, k;
    pii tmp;
    k = sz(adj[u]);

    for(i=0;i<k;i++)
    {
        v = adj[u][i].X;
        if(col[v]) continue;
        tmp = dfs(v);
        if(tmp.Y + adj[u][i].Y > ret.Y)
            ret = MP(tmp.X , tmp.Y + adj[u][i].Y);
    }

    return ret;
}

void solve(int u, int cost, int f)
{
    col[u] = 1;
    dp[u][f] = cost;

    int i, j, k;
    k = sz(adj[u]);

    for(i=0;i<k;i++)
    {
        j = adj[u][i].X;
        if(col[j]) continue;
        solve(j, cost+adj[u][i].Y, f);
    }
}

int main()
{
    int t=0, test, i, j, k, l, n, start, end;
    pii tmp;

    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++) adj[i].clear();

        for(i=0;i<n-1;i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j].push_back( MP(k,l) );
            adj[k].push_back( MP(j,l) );
        }

        memset(col, 0, sizeof(bool)*(n+2));
        tmp = dfs(0);
        start = tmp.X;

        memset(col, 0, sizeof(bool)*(n+2));
        tmp = dfs(start);
        end = tmp.X;

        memset(col, 0, sizeof(bool)*(n+2));
        solve(start, 0, 0);

        memset(col, 0, sizeof(bool)*(n+2));
        solve(end, 0, 1);

        printf("Case %d:\n",++t);
        for(i=0;i<n;i++)
            printf("%d\n",max( dp[i][0], dp[i][1] ) );
    }

    return 0;
}
