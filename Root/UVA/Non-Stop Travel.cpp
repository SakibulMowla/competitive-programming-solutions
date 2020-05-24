#include "stdio.h"
#include "string.h"
#include "vector"
#include "queue"
#include "iostream"

using namespace std;
#define SZ 15
vector <int> edge[SZ] , cost[SZ];
int dist[SZ] , par[SZ] , path[SZ];

struct data
{
    int city , dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

priority_queue <data> pq;
const int inf = 1000000000;
int dijkstra(int start,int target)
{
    data u,v;
    int i,ucost;
    for(i=0;i<SZ;i++)
        dist[i] = inf;
    dist[start] = 0;
    u.city = start;
    u.dist = 0;
    pq.push(u);

    while( !pq.empty() )
    {
        u = pq.top();
        pq.pop();
        ucost = dist[u.city];
        for(i=0;i<edge[u.city].size();i++)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + ucost;  // :P
            if( v.dist < dist[v.city] )
            {
//                printf("city = %d  dist = %d\n",v.city,v.dist);
                dist[v.city] = v.dist;
                par[v.city] = u.city;
                pq.push(v);
            }
        }
    }
    return dist[target];
}

void path_print(int start,int target)
{
    int i,j,k;
    path[0] = target;
    for(i=1,j=0;;i++,j++)
    {
        path[i] = par[path[j]];
        if(path[i] == start)
            break;
    }
    printf(" Path = %d",path[i]);
    for(j = i-1;j>=0;j--)
        printf(" %d",path[j]);
    printf(";");
}

int main()
{
    int n,i,j,roads,in,co,delay,start,target,test;
    test = 0;
//    freopen("1.txt","r",stdin);
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&roads);
            for(j=1;j<=roads;j++)
            {
                scanf("%d %d",&in,&co);
                edge[i].push_back(in);
                cost[i].push_back(co);
            }
        }
        scanf("%d %d",&start,&target);
        delay = dijkstra(start,target);
        printf("Case %d:",++test);
        path_print(start,target);
        printf(" %d second delay\n",delay);
        for(i=0;i<=n;i++)
            edge[i].clear(),cost[i].clear();
    }

    return 0;
}
