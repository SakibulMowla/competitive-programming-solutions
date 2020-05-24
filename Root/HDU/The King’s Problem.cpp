#include "stdio.h"
#include "vector"
#include "stack"
#include "string.h"
#include "iostream"

using namespace std;

#define sz(a) (int)a.size()
#define SZ 5010

vector <int> adj[SZ];
vector <int> n_adj[SZ];
int col[SZ], low[SZ], tim[SZ], timer;
int group_id[SZ], compo;
stack <int> S;

void scc(int u)
{
    int i, v, k, tem;

    col[u] = 1;
    low[u] = tim[u] = timer++;
    S.push(u);
    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tim[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tim[u])
    {
//        printf("u = %d\n",u);
        do
        {
//            printf("yes %d %d\n",tem,u);
            tem = S.top();
            S.pop();
            group_id[tem] = compo;
            col[tem] = 2;
        }
        while(tem != u);
        compo++;
    }
}

void process_scc(int n)
{
    int i;

    timer = compo = 0;

    memset(col, 0, sizeof(int)*(n+2));
    while(!S.empty()) S.pop();

    for(i=0; i<n; i++)
        if(col[i] == 0)
            scc(i);
    return;
}



void make_DAG(int n)
{
    int i, j, k, u, v;

    for(i=0; i<=compo; i++)
        n_adj[i].clear();

    for(i=0; i<n; i++)
    {
        k = sz(adj[i]);
        for(j=0; j<k; j++)
        {
            u = group_id[i];
            v = group_id[ adj[i][j] ];
            if(u != v)
                n_adj[u].push_back(v);
        }
    }
}


int par[SZ];

bool dfs(int u)
{
//    printf("u = %d\n",u);
    if(col[u])
        return false;
    int i, j ,k;

    k = sz(n_adj[u]);

    for(i=0; i<k; i++)
    {
        j = n_adj[u][i];
        if(col[j] == 0)
        {
            col[j] = 1;
            if(par[j] == -1 || dfs(par[j]))
            {
                par[j] = u;
                return true;
            }
        }
    }

    return false;
}

int bpm(int n)
{
    int i, ret = 0;

    for(i=0; i<=n; i++)
        par[i] = -1;

    for(i=0; i<n; i++)
    {
//        printf("i = %d\n",i);
        memset(col, 0, sizeof(int)*(n+2));
        if(dfs(i))
            ret++;
    }

//    printf("ret = %d\n",ret);

    return ret;
}

int main()
{
    int t, n, m, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);

        for(i=0; i<=n; i++)
            adj[i].clear();

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            --j, --k;
            adj[j].push_back(k);
        }

//        printf("ok\n");
        process_scc(n);
//        printf("ok\n");
        make_DAG(n);

//        printf("compo = %d\n",compo);

        printf("%d\n",compo-bpm(compo));
    }

    return 0;
}



/*
3

4 3
1 2
1 3
4 2

ans = 2

4 3
1 2
4 2
1 3

ans = 2

6 6
1 2
2 3
3 1
2 4
2 6
5 4


ans = 2
*/





