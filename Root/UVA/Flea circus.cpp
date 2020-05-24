#include "bits/stdc++.h"
using namespace std;

#define SZ 5010
#define SZ1 15

#define sz(a) (int)a.size()

inline void read (int &n)
{
    n = 0;
    int i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

int n, par[SZ][SZ1], dist[SZ][SZ1], lev[SZ], col[SZ];
vector <int> adj[SZ];

void dfs(int u)
{
    col[u] = 1;
    int i, j, k;
    k = sz(adj[u]);
    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(!col[j])
        {
            lev[j] = lev[u] + 1;
            par[j][0] = u;
            dist[j][0] = 1;
            dfs(j);
        }
    }
}

void process()
{
    int i, j , h, l;
    for(h=1; (1<<h)<=n; h++);
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

int path, ancs;

void query(int p,int q)
{
    path = 0;

    if(lev[p] < lev[q]) swap(p, q);
    int i, h;
    for(h=1; (1<<h)<=lev[p]; h++);
    --h;

    for(i=h; i>=0; i--)
    {
        if(lev[p] - (1<<i) >= lev[q])
        {
            path += dist[p][i];
            p = par[p][i];
        }
    }
    if(p == q)
    {
        ancs = p;
        return;
    }
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
    ancs = par[p][0];
    path += 2;
    return;
}

int ancs_dist(int p, int q)
{
    int i, h, cost=0;
    for(h=1; (1<<h)<=lev[p]; h++);
    --h;
    for(i=h; i>=0; i--)
    {
        if(lev[p]-(1<<i) >= lev[q])
        {
            cost += dist[p][i];
            p = par[p][i];
        }
    }
    return cost;
}

int stone_throw(int node,int _throw)
{
    int i, h;
    for(h=1; (1<<h)<=lev[node]; h++);
    --h;
    for(i=h; i>=0; i--)
    {
        if(_throw - (1<<i) >= 0)
        {
            node = par[node][i];
            _throw -= (1<<i);
        }
    }
    return node;
}

int main()
{
    int i, j, k, q, a, b;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            col[i] = 0;
        }
        for(i=0; i<n-1; i++)
        {
            read(j);
            read(k);
            adj[j].push_back(k);
            adj[k].push_back(j);
        }
        process();
        read(q);
        while(q--)
        {
            read(i);
            read(j);
            query(i, j);
            a = ancs_dist(i, ancs);
            b = ancs_dist(j, ancs);
            if( !(path & 1) )
            {
                path /= 2;
                if(a >= path)
                    a = stone_throw(i, path);
                else
                    a = stone_throw(j, path);
                printf("The fleas meet at %d.\n",a);
            }
            else
            {
                if( a >= (path>>1)+1 )
                {
                    a = stone_throw(i, path>>1);
                    b = stone_throw(i, (path>>1)+1);
                }
                else if( b >= (path>>1)+1 )
                {
                    a = stone_throw(j, path>>1);
                    b = stone_throw(j, (path>>1)+1);
                }
                if(a > b) swap(a, b);
                printf("The fleas jump forever between %d and %d.\n",a ,b);
            }
        }

    }

    return 0;
}
