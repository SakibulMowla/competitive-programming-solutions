using namespace std;

#include "stdio.h"
#include "vector"
#include "stack"
#include "iostream"

#define SZ 50010
#define sz(a) ((int)a.size())

vector <int> adj[SZ];
int dis[SZ], low[SZ], col[SZ], group[SZ], element[SZ], small[SZ], dp[SZ], tym, compo;
stack <int> S;

void init(int n)
{
    int i;
    while(!S.empty()) S.pop();
    tym = compo = 0;
    for(i=0; i<=n; i++)
    {
        adj[i].clear();
        col[i] = 0;
        dp[i] = -1;
    }
}

void tarjan(int u)
{
    int i, j, k;
    col[u] = 1;
    dis[u] = low[u] = tym++;
    S.push(u);

    k = sz(adj[u]);

    for(i=0; i<k; i++)
    {
        j = adj[u][i];
        if(col[j] == 1)
            low[u] = min(low[u], dis[j]);
        else if(col[j] == 0)
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
    }

    if(low[u] == dis[u])
    {
        int k = 0, s=1e9;
        do
        {
            j = S.top();
            S.pop();
            group[j] = compo;
            col[j] = 2;
            s = min(s, j);
            k++;
        }
        while(j != u);

        element[compo] = k;
        small[compo] = s;
        compo++;
    }
}

vector <int> dag[SZ];

void make_DAG(int n)
{
    int i, j, k, p, q;

    for(i=0; i<compo; i++)
        dag[i].clear();

    for(i=1; i<=n; i++)
    {
        k = sz(adj[i]);
        for(j=0; j<k; j++)
        {
            p = group[i];
            q = group[ adj[i][j] ];
            if(p != q)
                dag[p].push_back(q);
        }
    }
}

int dfs(int u)
{
    int &ret = dp[u];
    if(ret != -1)   return ret;
    int i, k;

    ret = element[u];
    k = sz(dag[u]);

    for(i=0; i<k; i++)
        ret += dfs(dag[u][i]);

    return ret;
}

int main()
{
    int t=0, test, n, i, j, k, tmp, best, node;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);
        init(n);
        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
        }
        for(i=1; i<=n; i++)
            if(!col[i])
                tarjan(i);
        make_DAG(n);
        best = 0;
        node = 1e9;
        for(i=0; i<compo; i++)
        {
            tmp = dfs(i);
            if(tmp > best)
            {
                best = tmp;
                node = small[i];
            }
            else if(tmp == best)
            {
                if(small[i] < node)
                    node = small[i];
            }
        }
        printf("Case %d: %d\n",++t, node);
    }

    return 0;
}
