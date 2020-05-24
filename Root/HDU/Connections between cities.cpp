#include "stdio.h"
#include "string.h"
#include "iostream"
#include "vector"

using namespace std;

#define SZ 10010
#define SZ1 20

#define mem(a, b) memset(a, b, sizeof(a))
#define sz(a) (long long)a.size()
#define clr(a) a.clear()

typedef long long ll;
const ll inf = 1e15;

ll par[SZ][SZ1] , dist[SZ][SZ1], lev[SZ], tree[SZ], treeno;
bool col[SZ];
vector <ll> adj[SZ], edge[SZ];

void dfs(ll u)
{
//    printf("dfs %lld\n",u);
    col[u] = 1;
    tree[u] = treeno;
    int i, j, k;
    k = sz(adj[u]);
    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j]) continue;
        lev[j] = lev[u] + 1;
        par[j][0] = u;
        dist[j][0] = edge[u][i];
        tree[j] = treeno;
        dfs(j);
    }
    return;
}

void process(int n)
{
//    printf("process:\n");
    int i, j, h;
    for(h=1; (1LL<<h)<=n; h++)
    {
        ;
    }
    --h;
    for(i=0; i<=n; i++)
    {
        col[i] = 0;
        for(j=0; j<=h; j++)
            par[i][j] = -1, dist[i][j] = 0;
    }
    treeno = 0;
    for(i=1; i<=n; i++)
    {
        if(!col[i])
        {
            lev[i] = 0;
            treeno++;
            dfs(i);
//            printf("i = %lld\n",i);
        }
    }
//    printf("h = %lld\n",h);
    for(j=1; j<=h; j++)
        for(i=1; i<=n; i++)
            if(par[i][j-1] != -1)
            {
                dist[i][j] = (ll)dist[i][j-1] + (ll)dist[ par[i][j-1] ][j-1];
                par[i][j] = par[ par[i][j-1] ][j-1];
//                printf("par[%lld][%lld] = %lld\n",i,j,par[i][j]);
            }
}

ll query(int p,int q)
{
//    printf("lev[%lld] = %lld  lev[%lld] = %lld\n",p,lev[p],q,lev[q]);
    if(lev[p] < lev[q]) swap(p, q);
    int i, j, h;
    ll path=0LL;
    for(h=1; (1LL<<h)<=lev[p]; h++)
    {
        ;
    }
    --h;
    for(i=h; i>=0; i--)
    {
        if(lev[p] - (1LL<<i) >= lev[q])
        {
//            printf("yes\n");
//            printf("i = %lld\n",i);
            path += dist[p][i];
            p = par[p][i];
//            printf("p = %lld\n",p);
        }
    }
    if(p == q) return path;
    for(i=h; i>=0; i--)
    {
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            path += dist[p][i] + dist[q][i];
            p = par[p][i];
            q = par[q][i];
        }
    }
    path += dist[p][0] + dist[q][0];
    return path;
}

int main()
{
//    freopen("2.txt","r",stdin);
//    freopen("1.txt","w",stdout);
    int n, m, q, i, j, k, l;
    ll ans;

    while(scanf("%d %d %d",&n,&m,&q) != EOF)
    {

        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            edge[i].clear();
            tree[i] = -1;
        }

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j].push_back(k);
            adj[k].push_back(j);
            edge[j].push_back(l);
            edge[k].push_back(l);
        }

        process(n);

        while(q--)
        {
            scanf("%d %d",&i,&j);
//        printf("tree[%lld] = %lld tree[%lld] = %lld \n",i,tree[i],j,tree[j]);
            if(tree[i] != tree[j]) printf("Not connected\n");
            else
            {
                ans = query(i, j);
                printf("%lld\n",ans);
            }
        }
    }

    return 0;
}

/*

9 5 10
1 2 1
3 1 1
5 4 1
8 7 1
9 8 1


*/
