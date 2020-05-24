#include "bits/stdc++.h"
using namespace std;

#define SZ 100010
#define SZ1 20
#define clr(a, b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
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

/// SCC Requirement
stack <int> S;
vector <int> adj[SZ], nadj[SZ];
int tim[SZ], low[SZ], com_id[SZ], no_com[SZ], comp, id;
int col[SZ], cycle_dist[SZ], rev_id[SZ];

/// LCA Reqirement
int dist[SZ][SZ1], par[SZ][SZ1], lev[SZ], tree_col[SZ], treeno;
int imd_chld[SZ];

void lca_dfs(int u, int cl, bool f)
{
    col[u] = 1;

    int i, v, k;

    k = sz(nadj[u]);

    for(i=0; i<k; i++)
    {
        v = nadj[u][i];
        if(col[v]) continue;
        lev[v] = lev[u] + 1;
        tree_col[v] = treeno;
        par[v][0] = u;
        dist[v][0] = 1;
        if(f)
        {
            imd_chld[v] = v;
            lca_dfs(v, v, 0);
        }
        else
        {
            imd_chld[v] = cl;
            lca_dfs(v, cl, 0);
        }
    }
}

void process()
{
    int i, j, k, h;

    for(i=0; i<=comp; i++)
    {
        col[i] = 0;
        tree_col[i] = 0;
    }

    for(h=1; (1<<h)<=comp; h++)
    {
        ;
    }
    h--;

    for(i=0; i<=comp; i++)
        for(j=0; j<= h; j++)
            par[i][j] = -1, dist[i][j] = 0;

    treeno = 0;

    for(i=1; i<= comp; i++)
    {
        if(no_com[i] > 1)
        {
//            printf("i = %d treeno = %d\n",i, treeno);
            treeno++;
            lev[i] = 0;
            tree_col[i] = treeno;
            lca_dfs(i, i, 1);
        }
    }

    for(j=1; j<=h; j++)
        for(i=1; i<= comp; i++)
            if(par[i][j-1] != -1)
            {
                dist[i][j] = dist[i][j-1] + dist[ par[i][j-1] ][j-1];
                par[i][j] = par[ par[i][j-1] ][j-1];
            }
}


int query(int p, int q, int u, int v)
{
    int tmp2=v;
    if(lev[p] < lev[q]) swap(p, q), tmp2 = u;

    int tmp = p;

    int i, j, h, path = 0;

    for(h=1; (1<<h)<=lev[p]; h++)
    {
        ;
    }
    h--;

    for(i=h; i>=0; i--)
    {
        if(lev[p] - (1<<i) >= lev[q])
        {
            path += dist[p][i];
            p = par[p][i];
        }
    }

    int koyta;

    if(p == q)
    {
        if(no_com[p] <= 1) return path;

        tmp = imd_chld[tmp];
        tmp = rev_id[tmp];
        tmp = adj[tmp][0];
        koyta = no_com[p];

        tmp = cycle_dist[tmp];
        tmp2 = cycle_dist[tmp2];

        if(tmp < tmp2) swap(tmp, tmp2);

        path += min( tmp-tmp2, koyta-(tmp-tmp2) );

        return path;
    }

    for(i=h;i>=0;i--)
    {
        if(par[p][i] != -1 && par[q][i] != -1 && par[p][i] != par[q][i])
        {
            path += dist[p][i] + dist[q][i];
            p = par[p][i];
            q = par[q][i];
        }
    }

    path += 2;

    tmp = rev_id[p];
    tmp = adj[tmp][0];
    tmp2 = rev_id[q];
    tmp2 = adj[tmp2][0];

    koyta = no_com[ com_id[tmp] ];
    tmp = cycle_dist[tmp];
    tmp2 = cycle_dist[tmp2];

    if(tmp < tmp2) swap(tmp, tmp2);

    path += min( tmp-tmp2, koyta-(tmp-tmp2) );

    return path;
}



void scc_dfs(int u,int cl)
{
    int v, k, i;

    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(com_id[v] != cl || cycle_dist[v]) continue;
        cycle_dist[v] = cycle_dist[u] + 1;
        scc_dfs(v, cl);
    }
}

void SCC(int u)
{
    col[u] = 1;
    low[u] = tim[u] = id++;
    S.push(u);

    int i, k, v, cnt=0;

    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            SCC(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tim[u])
    {
        do
        {
            v = S.top();
            S.pop();
            cnt++;
            com_id[v] = comp;
            col[v] = 2;
            rev_id[comp] = v;
        }
        while(u != v);

        no_com[comp] = cnt;
        comp++;

        if(cnt > 1)
        {
            cycle_dist[u] = 1;
            scc_dfs(u, comp-1);
        }
    }
}

void make_dag(int n)
{
    int i, v;

    for(i=1; i<=n; i++)
    {
        v = adj[i][0];
        if(com_id[i] != com_id[v])
        {
            nadj[ com_id[i] ].pb( com_id[v] );
            nadj[ com_id[v] ].pb( com_id[i] );
        }
    }
}


int main()
{
//    freopen("1.txt","r",stdin);
    int n, i, j, k, q, u, v;

    while(~scanf("%d",&n))
    {
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            nadj[i].clear();
            col[i] = 0;
            cycle_dist[i] = 0;
        }

        for(i=1; i<=n; i++)
        {
            read(j);
            adj[i].pb(j);
        }

        id = 0;
        comp = 1;

        for(i=1; i<=n; i++)
        {
            if(!col[i])
                SCC(i);
        }

        make_dag(n);


        ////printing DAG ------------>
//        printf("Printing DAG --------->\n");
//        for(i=1;i<=comp;i++)
//        {
//            printf("comp %d ===> ",i);
//            k = sz(nadj[i]);
//            for(j=0;j<k;j++)
//                printf(" %d",nadj[i][j]);
//            printf("\n");
//        }
//        printf("DAG Printed ----------->\n");

        process();

        read(q);
        int koyta, icol, jcol;

        while(q--)
        {
            read(i);
            read(j);
            u = com_id[i];
            v = com_id[j];
//            printf("tree : %d %d \n",tree_col[u], tree_col[v]);
            if(tree_col[u] != tree_col[v])
            {
//                printf("Diffrent Tree\n");
                puts("-1");
            }
            else if(u == v)
            {
                koyta = no_com[u];
                icol = cycle_dist[i];
                jcol = cycle_dist[j];
                if(icol > jcol) swap(icol, jcol);
                printf("%d\n",min( jcol-icol, koyta-(jcol-icol) ));
            }
            else
                printf("%d\n",query(u, v, i, j));
        }

    }

    return 0;
}


/*

DAG Check --------
10
2 3 5 3 4 5 6 9 10 8
-------------

Cycle Test --------
5
2 3 4 5 1
1
1 4
ans = 2

Diffrent Tree -------
7
2 3 4 5 1 7 6
3
1 6
5 7
3 3

Mix ---------------
10
2 3 5 3 4 5 6 9 10 8
4
6 6
3 4
5 8
10 9

Mix-------------
13
2 3 5 3 4 5 6 9 10 8 9 8 12

*/
