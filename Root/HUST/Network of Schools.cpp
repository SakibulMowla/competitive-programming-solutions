#include "stdio.h"
#include "string.h"
#include "iostream"
#include "vector"
#include "stack"

using namespace std;

#define sz(a) (int)a.size()
#define SZ 110

vector <int> adj[SZ], nadj[SZ];
int col[SZ], low[SZ], tym[SZ], group[SZ], in[SZ], out[SZ];
int timer, compo;
stack <int> S;

void scc(int u)
{
    int i, k, v, tem;
    col[u] = 1;
    low[u] = tym[u] = timer++;
    S.push(u);
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        v = adj[u][i];
        if(col[v] == 1)
            low[u] = min(low[u], tym[v]);
        else if(col[v] == 0)
        {
            scc(v);
            low[u] = min(low[u], low[v]);
        }
    }

    if(low[u] == tym[u])
    {
        compo++;
        do
        {
            tem = S.top();
            S.pop();
            group[tem] = compo;
            col[tem] = 2;
        }
        while(tem != u);
    }
}

void make_DAG(int n)
{
    int i, j, k, u, v;

    for(i=1; i<=n; i++)
    {
        k = sz(adj[i]);
        for(j=0; j<k; j++)
        {
            u = group[i];
            v = group[adj[i][j]];
            if(u != v)
                nadj[u].push_back(v), out[u]++, in[v]--;
        }
    }
}

void dfs(int u)
{
    col[u] = 1;

    int i, j, k;

    k = sz(nadj[u]);

    for(i=0; i<k; i++)
    {
        j = nadj[u][i];
        if(col[j]) continue;
        dfs(j);
    }

    return ;
}

int main()
{
    int n, i, j, ans1, ans2, indeg, outdeg;

    scanf("%d",&n);

    for(i=1; i<=n; i++)
        while(scanf("%d",&j) == 1 && j)
            adj[i].push_back(j);

    for(i=1; i<=n; i++)
        if(!col[i])
            scc(i);

    make_DAG(n);

    indeg = outdeg = ans2 = 0;

    if(compo > 1)
    {
        for(i=1; i<=compo; i++)
        {
            if(in[i] == 0) indeg++;
            if(out[i] == 0) outdeg++;
        }
        ans2 = max(indeg, outdeg);
    }

    memset(col, 0, sizeof(int)*(compo+2));
    while(!S.empty()) S.pop();

    for(i=1; i<=compo; i++)
    {
        if(col[i]) continue;
        dfs(i);
        S.push(i);
    }

    ans1 = 0;
    memset(col, 0, sizeof(int)*(compo+2));

    while(!S.empty())
    {
        i = S.top();
        S.pop();
        if(col[i]) continue;
        ans1++;
        dfs(i);
    }

    printf("%d\n%d\n",ans1, ans2);

    return 0;
}
