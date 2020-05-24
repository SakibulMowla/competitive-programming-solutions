#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define SZ 100010
#define SZ1 20

#define sz(a) (int)a.size()

vector <int> adj[SZ];
vector <ll> cost[SZ];

int par[SZ][SZ1], lev[SZ];
bool col[SZ];
int n;
ll dist[SZ][SZ1];

void dfs(int u)
{
    col[u] = 1;
    int i, j ,k;
    k = sz(adj[u]);
    for(i=0; i<k; i++)
    {
        j = adj[u][i];

        if(col[j]) continue;
        lev[j] = lev[u] + 1;
        par[j][0] = u;
        dist[j][0] = cost[u][i];
        dfs(j);
    }
}

void process()
{
    int i, j, h, l;
    for(h=1; (1<<h)<=n; h++)
    {
        ;
    }
    --h;
    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            par[i][j] = -1, dist[i][j] = 0;
    lev[1] = 0;
    dfs(1);
    for(l=1; l<=h; l++)
        for(i=1; i<=n; i++)
            if(par[i][l-1] != -1)
            {
                dist[i][l] = dist[i][l-1] + dist[ par[i][l-1] ][l-1];
                par[i][l] = par[ par[i][l-1] ][l-1];
            }
}

ll query(int p,int q)
{
    if(lev[p] < lev[q]) swap(p, q);
    int i, h;
    ll cost = 0;
    for(h=1; (1<<h)<=lev[p]; h++)
    {
        ;
    }
    --h;
    for(i=h; i>=0; i--)
    {
        if(lev[p]-(1<<i) >= lev[q])
        {
            cost += dist[p][i];
            p = par[p][i];
        }
    }
    if(p == q)  return cost;
    for(i=h;i>=0;i--)
    {
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            cost += dist[p][i];
            cost += dist[q][i];
            p = par[p][i];
            q = par[q][i];
        }
    }

    cost += dist[p][0] + dist[q][0];
    return cost;
}

int main()
{
    int q, i, j;
    ll k;
    bool blank;

    while(1)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            cost[i].clear();
            col[i] = 0;
        }
        for(i=2; i<=n; i++)
        {
            scanf("%d %lld",&j,&k);
            j++;
            adj[i].push_back(j);
            adj[j].push_back(i);
            cost[i].push_back(k);
            cost[j].push_back(k);
        }
        process();
        scanf("%d",&q);
        blank = 0;
        while(q--)
        {
            scanf("%d %d",&i,&j);
            i++, j++;
            if(blank)  printf(" ");
            else blank = 1;
            printf("%lld",query(i, j));
        }
        printf("\n");
    }

    return 0;
}
