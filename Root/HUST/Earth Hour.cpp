#include "stdio.h"
#include "vector"
#include "math.h"
#include "queue"
#include "iostream"

using namespace std;

const int inf = 1e7;

#define SZ 210
#define sz(a) (int)a.size()

struct data
{
    int to, cost;
    bool operator < (const data &x) const
    {
        return cost > x.cost;
    }
    data()
    {

    }
    data(int a,int b)
    {
        to = a;
        cost = b;
    }
};

priority_queue <data> pq;
vector <int> adj[SZ];

void dijkstra(int start, int dist[],int n)
{
    while(!pq.empty()) pq.pop();

    int i, j, k, w;
    data u;

    for(i=0; i<n; i++)
        dist[i] = inf;

    dist[start] = 1;
    pq.push( data(start, 1) );

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        k = sz(adj[u.to]);

        for(i=0; i<k; i++)
        {
            j = adj[u.to][i];
            if(dist[j] > u.cost + 1)
            {
                dist[j] = u.cost + 1;
                pq.push( data(j, dist[j]) );
            }
        }
    }

    return ;
}

struct point
{
    int x, y, z;
};

point light[SZ];

int main()
{
    int dist1[SZ], dist2[SZ], dist3[SZ];
    int n, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            adj[i].clear(), scanf("%d %d %d",&light[i].x, &light[i].y, &light[i].z);

        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                if(pow(light[i].z + light[j].z, 2) >= pow(light[i].x-light[j].x, 2) + pow(light[i].y-light[j].y, 2))
                    /*printf("conn %d %d\n",i,j),*/ adj[i].push_back(j),  adj[j].push_back(i);

        dijkstra(0, dist1, n);
        dijkstra(1, dist2, n);
        dijkstra(2, dist3, n);

        k = inf;

        for(i=0; i<n; i++)
        {
            j = dist1[i] + dist2[i] + dist3[i] - 2;
//            printf("i = %d j = %d\n",i,j);
            k = min(k, j);
        }

        if(k >= inf) k = -1;
        else k = n - k;
        printf("%d\n",k);
    }

    return 0;
}
