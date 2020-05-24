#include "stdio.h"
#include "vector"
#include "math.h"
#include "iostream"
#include "algorithm"

using namespace std;

#define SZ 210
int par[SZ];

struct data
{
    int x, y;
};

data point[SZ];

struct data1
{
    int u, v;
    float cost;
};

vector <data1> graph;

bool comp(data1 p,data1 q)
{
    return p.cost < q.cost;
}

struct data2
{
    int u;
    float cost;
};

vector <data2> adj[SZ];

int find(int r)
{
    if(r == par[r])
        return r;
    return par[r] = find(par[r]);
}

void mst(int n)
{
    int i, k, x, y;
    data2 u;
    k = graph.size();
    for(i=0; i<k; i++)
    {
        x = find( graph[i].u );
        y = find( graph[i].v );
        if(x == y) continue;
        par[x] = y;
        u.u = graph[i].v;
        u.cost = graph[i].cost;
        adj[graph[i].u].push_back(u);
        u.u = graph[i].u;
        u.cost = graph[i].cost;
        adj[graph[i].v].push_back(u);
    }
}

bool col[SZ];
float ans;
bool found;

void dfs(int u,float cost)
{
    if(found) return;
    col[u] = 1;
    if(u == 1)
    {
        ans = cost;
        found = 1;
        return;
    }
    int i, j, k;
    k = adj[u].size();
    for(i=0; i<k; i++)
    {
        j = adj[u][i].u;
        if(col[j]) continue;
        dfs(j, max(cost, adj[u][i].cost));
    }
    return ;
}

int main()
{
    int test=0,n, i, j, k;
    data1 u;

    while(scanf("%d",&n) == 1 && n)
    {
        for(i=0; i<n; i++)
            scanf("%d %d",&point[i].x,&point[i].y);
        graph.clear();
        for(i=0; i<j; i++)
            for(j=i+1; j<n; j++)
            {
                u.u = i;
                u.v = j;
                u.cost = sqrt( pow((float)point[i].x-(float)point[j].x, 2) + pow((float)point[i].y-(float)point[j].y, 2) );
                graph.push_back(u);
            }
        for(i=0; i<n; i++)
        {
            adj[i].clear();
            par[i] = i;
            col[i] = 0;
        }
        sort(graph.begin(), graph.end(), comp);
        mst(n);
        dfs(0, 0);
        found = 0;
        printf("Scenario #%d\n",++test);
        printf("Frog Distance = %.3f\n\n",ans);
    }

    return 0;
}
