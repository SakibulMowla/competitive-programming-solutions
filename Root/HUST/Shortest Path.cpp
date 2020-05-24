#include "iostream"
#include "stdio.h"
#include "vector"
#include "queue"

using namespace std;

const int inf = 1e9;
#define SZ 310
#define sz(a) (int)a.size()

struct data
{
    int to, cost;
    bool operator < (const data &x) const
    {
        return cost > x.cost;
    }
    data(){}
    data(int a,int b)
    {
        to = a;
        cost = b;
    }
};

vector <data> adj[SZ];
priority_queue <data> pq;
bool mark[SZ];
int dist[SZ];

int dijkstra(int start,int end,int n)
{
    while(!pq.empty())  pq.pop();

    int i, j, k, w;
    data u;

    for(i=0;i<=n;i++)
        dist[i] = inf;

    dist[start] = 0;
    pq.push( data(start, 0) );

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        k = sz(adj[u.to]);

        for(i=0;i<k;i++)
        {
            j = adj[u.to][i].to;
            w = adj[u.to][i].cost;
            if(!mark[j]) continue;
            if(dist[j] > u.cost + w)
            {
                dist[j] = u.cost + w;
                pq.push( data(j, dist[j]) );
            }
        }
    }

    return dist[end];
}

int main()
{
//    freopen("1.txt","r",stdin);
    bool blank = false;

    int n, m, q, i, j, k, l, test=0;

    while(scanf("%d %d %d",&n,&m,&q) == 3)
    {
        if(n == 0 && m == 0 && q == 0)
            break;

        if(blank) printf("\n");
        else blank = true;
        printf("Case %d:\n",++test);

        for(i=0;i<=n;i++)
        {
            adj[i].clear();
            mark[i] = 0;
        }

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j].push_back( data(k, l) );
        }
        while(q--)
        {
            scanf("%d",&i);
            if(!i)
            {
                scanf("%d",&j);
                if(mark[j]) printf("ERROR! At point %d\n",j);
                mark[j] = 1;
            }
            else
            {
                scanf("%d %d",&j,&k);
                if(!mark[j] || !mark[k]) printf("ERROR! At path %d to %d\n",j,k);
                else
                {
                    l = dijkstra(j, k, n);
                    if(l >= inf) printf("No such path\n");
                    else printf("%d\n",l);
                }
            }
        }
    }

    return 0;
}
