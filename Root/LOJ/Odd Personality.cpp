#include "bits/stdc++.h"
using namespace std;

#define SZ 10010
#define sz(a) (int)a.size()
#define MP(a, b) make_pair(a, b)

#define X first
#define Y second

vector <int> adj[SZ];
int tym[SZ], low[SZ], timer, cnt;
int col[SZ], par[SZ];
bool brid[SZ];

void BCC(int u,int parent)
{
//    printf("u = %d\n",u);
    tym[u] = low[u] = timer++;
    col[u] = 1;

    int i, j, k, us, vs, v, tmp;

    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(v == parent) continue;

        if(!col[v])
        {
            par[v] = u;
            BCC(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tym[u])
            {
                brid[v] = true;
            }
        }

        else if(col[v] == 1)
            low[u] = min(low[u], tym[v]);
    }

    col[v] = 2;
}

int dist[SZ];
bool found;
bool rong[SZ];

void dfs(int u,int path)
{
    dist[u] = path;
    rong[u] = 1;
    cnt++;

    int i, v, k;

    k = sz(adj[u]);

    for(i=0;i<k;i++)
    {
        v = adj[u][i];
        if( (brid[u] && par[u] == v) || (brid[v] && par[v] == u) ) continue;

        if(!rong[v])
            dfs(v, path+1);
        else if(rong[v])
            if( (dist[u]-dist[v]) % 2 == 0 )
                found = 1;
    }
}

int main()
{
//    freopen("1.txt","r",stdin);
    int test = 0, t, n, m, i, j, k, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<=n; i++)
        {
            low[i] = tym[i] = col[i] = rong[i] = brid[i] = 0;
            par[i] = i;
            adj[i].clear();
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }

        timer = 0;
        ans = 0;

        for(i=0; i<n; i++)
            if(!tym[i])
                BCC(i, -1);

        for(i=0;i<n;i++)
        {
            if(!rong[i] && col[i])
            {
                found = false;
                cnt = 0;
                dfs(i, 0);
                if(found)
                    ans += cnt;
            }
        }

        printf("Case %d: %d\n",++test, ans);
    }

    return 0;
}
