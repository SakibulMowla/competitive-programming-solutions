#include "stdio.h"
#include "vector"
#include "queue"
#include "iostream"

using namespace std;

const int inf = 1e9;
#define SZ 1010

struct data
{
    int to, cost;
    bool operator < (const data&x) const
    {
        return cost > x.cost;
    }
    data()
    {

    }
    data(int a,int b)
    {
        to  = a;
        cost = b;
    }
};

priority_queue <data> pq;

void dijkstra(int n, int start, int dist[], vector<data>adj[])
{
    while(!pq.empty()) pq.pop();

    int i, j, k, w;
    data u, v;

    for(i=0; i<=n; i++)
        dist[i] = inf;

    dist[start] = 0;
    pq.push(data(start, 0));

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        k = adj[u.to].size();

        for(i=0; i<k; i++)
        {
            j = adj[u.to][i].to;
            w = adj[u.to][i].cost;
            if(dist[j] > u.cost + w)
            {
                dist[j] = u.cost + w;
                pq.push(data(j, dist[j]));
            }
        }
    }

    return;
}

int main()
{
    vector <data> adj1[SZ], adj2[SZ];
    int dist1[SZ], dist2[SZ];

    int n, m, start, i, u, v, w;

    scanf("%d %d %d",&n,&m,&start);

    for(i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj1[ u ].push_back( data( v, w ) );
        adj2[ v ].push_back( data( u, w ) );
    }

    dijkstra(n, start, dist1, adj1);
    dijkstra(n, start, dist2, adj2);

    start = 0;

    for(i=1; i<=n; i++)
        start = max(start, dist1[i]+dist2[i]);

    printf("%d\n",start);

    return 0;
}
