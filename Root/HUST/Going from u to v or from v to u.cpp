#include "stdio.h"
#include "vector"
#include "stack"
#include "queue"
#include "iostream"

using namespace std;

#define SZ 1010

vector <int> adj[SZ], nadj[SZ];
int low[SZ], tym[SZ], col[SZ], timer, compo;
int group[SZ], in[SZ], n;
stack <int> S;
queue <int> Q;

void scc(int u)
{
    int i, v, tem, k;
    col[u] = 1;
    low[u] = tym[u] = timer++;
    k = adj[u].size();
    S.push(u);
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
        do
        {
            tem = S.top();
            S.pop();
            col[tem] = 2;
            group[tem] = compo;
        }
        while(tem != u);
        compo++;
    }

    return;
}

void make_DAG()
{
    int i, j, k, u, v;
    for(i=1;i<=n;i++)
    {
        k = adj[i].size();
        for(j=0;j<k;j++)
        {
            u = group[i];
            v = group[adj[i][j]];
            if(u != v)
                nadj[u].push_back(j), in[v]++;
        }
    }
}

bool top_sort()
{
    while(!Q.empty()) Q.pop();
    int i, j, k, v, top=0;
    for(i=0;i<compo;i++)
        if(in[i] == 0)
            Q.push(i), top++;
    while(!Q.empty())
    {
        if(top > 1)
            return false;
        j = Q.front();
        top--;
        Q.pop();
        k = nadj[j].size();
        for(i=0;i<k;i++)
        {
            v = nadj[j][i];
            in[v]--;
            if(in[v] == 0)
                Q.push(v),top++;
        }
    }

    return true;
}

int main()
{
    int t, i, j, k, m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&n,&m);
        while(!S.empty())
            S.pop();
        for(i=0; i<=n; i++)
        {
            adj[i].clear();
            col[i] = 0;
            low[i] = 0;
            tym[i] = 0;
        }
        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            adj[j].push_back(k);
        }

        compo = timer = 0;

        for(i=1; i<=n; i++)
            if(col[i] == 0)
                scc(i);

        for(i=0;i<=compo;i++)
            nadj[i].clear(), in[i] = 0;

        make_DAG();

        if(top_sort()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
