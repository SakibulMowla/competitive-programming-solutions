#include "stdio.h"
#include "string.h"
#include "vector"

using namespace std;

#define SZ 50010
#define SZ1 20

int par[SZ][SZ1], dist[SZ][SZ1], lev[SZ], n;
bool col[SZ];
vector <int> adj[SZ], cost[SZ];

void dfs(int u)
{
//    printf("%d\n",u);
    col[u] = 1;
    int i, j, k;

    k = adj[u].size();

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j]) continue;
        lev[j] = lev[u] + 1;
        par[j][0] = u;
        dist[j][0] = cost[u][i];
        dfs(j);
    }

    return ;
}

void process()
{
    int i, j, h;

    for(h=1; (1<<h)<=n; h++)
    {
        ;
    }
    h--;

    for(i=0; i<=n; i++)
        for(j=0; j<=h; j++)
            par[i][j] = -1, dist[i][j] = 0;

    lev[1] = 0;
    dfs(1);

    for(j=1; j<=h; j++)
        for(i=1; i<=n; i++)
            if(par[i][j-1] != -1)
            {
                dist[i][j] = dist[i][j-1] + dist[ par[i][j-1] ][j-1];
                par[i][j] = par[ par[i][j-1] ][j-1];
            }
}

int root, path;

void query(int p,int q)
{
    if(lev[p] < lev[q]) swap(p, q);

    int i, j, h;
    path = 0;

    for(h=1; (1<<h)<=lev[p]; h++)
    {
        ;
    }
    h--;

//    printf("h = %d\n",h);

    for(i=h; i>=0; i--)
    {
        if(lev[p]-(1<<i) >= lev[q])
        {
            path += dist[p][i];
            p = par[p][i];
        }
    }

//    printf("h = %d\n",h);

    if(p == q)
    {
        root = p;
        return;
    }

//    printf("h = %d\n",h);

    for(i=h; i>=0; i--)
    {
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            path += dist[p][i];
            path += dist[q][i];
            p = par[p][i];
            q = par[q][i];
        }
    }

    path += dist[p][0] + dist[q][0];
    root = par[p][0];

    return ;
}

int main()
{
//    freopen("1.txt","r",stdin);
    int i, j, k, l, q, par1, par2, par3, cost1, cost2, cost3, ans;
    bool blank = false;

    while(scanf("%d",&n) == 1)
    {
        if(blank)
            printf("\n");
        else
            blank = true;

        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            cost[i].clear();
            col[i] = 0;
        }

        for(i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            j++,k++;
            adj[j].push_back(k);
            adj[k].push_back(j);
            cost[j].push_back(l);
            cost[k].push_back(l);
        }

        process();
        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d %d",&i,&j,&k);
            i++,j++,k++;

//            printf("ok\n");

            query(i, j);
            par1 = root;
            cost1 = path;

//            printf("ok\n");

            query(j, k);
            par2 = root;
            cost2 = path;

            query(k, i);
            par3 = root;
            cost3 = path;

            if(par1 == par2 && par2 == par3)
            {
                ans = cost1;
                query(par1, k);
                ans += path;
            }

            else if(par1 == par2)
            {
                ans = cost3;
                query(par3, j);
                ans += path;
            }

            else if(par2 == par3)
            {
                ans = cost1;
                query(par1, k);
                ans += path;
            }

            else if(par3 == par1)
            {
                ans = cost2;
                query(par2, i);
                ans += path;
            }

            printf("%d\n",ans);
//            printf("yes\n");
        }
    }

    return 0;
}
