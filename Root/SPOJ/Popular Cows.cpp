#include "stdio.h"
#include "vector"
#include "iostream"
#include "stack"
using namespace std;
#define SZ 10010
#define sz(a) (int)a.size()

int dis[SZ], low[SZ], group[SZ], element[SZ], col[SZ], out[SZ], tym, compo;
vector <int> adj[SZ];
stack <int> S;

void tarjan(int u)
{
    int i, j, k;

    dis[u] = low[u] = tym++;
    S.push(u);
    col[u] = 1;
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
        k = 0;
        do
        {
            j = S.top();
            S.pop();
            col[j] = 2;
            group[j] = compo;
            k++;
        }
        while(j != u);
        element[compo] = k;
        compo++;
    }
}

int main()
{
    int i, j, k, n, m, p, q;

    scanf("%d %d",&n,&m);

    for(i=0; i<m; i++)
    {
        scanf("%d %d",&j,&k);
        adj[j].push_back(k);
    }

    for(i=1; i<=n; i++)
        if(!col[i])
            tarjan(i);

    for(i=1; i<=n; i++)
    {
        k = sz(adj[i]);
        for(j=0; j<k; j++)
        {
            p = group[i];
            q = group[ adj[i][j] ];
            if(p != q)
                out[p]++;
        }
    }

    k = 0;
    for(i=0; i<compo; i++)
        if(!out[i])
        {
            k++;
            if(k == 2)
            {
                j=0;
                break;
            }
            j = element[i];
        }

    printf("%d\n",j);

    return 0;
}
