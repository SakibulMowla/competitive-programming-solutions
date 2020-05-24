#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define SZ 500
#define FOR(a,b) for(a=0;a<b;a++)
#define inf 1<<28

vector <int> edge[SZ+5] , cost[SZ+5];
int dist[SZ];

void init(int n)
{
    int i;
    for(i=0; i<n; i++)
        cost[i].clear() , edge[i].clear() , dist[i] = inf;
}

struct data
{
    int city , distance;
    bool operator < (const data& p) const
    {
        return distance > p.distance;
    }
};



void dijkstra(int start)
{
    int i,ucost;
    data u,v;
    priority_queue <data> q;
    u.city = start , u.distance = 0;
    q.push( u );
    dist[start] = 0;
    while( !q.empty() )
    {
        u = q.top() , q.pop();
        ucost = dist[u.city];

        for(i=0; i<edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i] ;

            if(dist[v.city] > max(ucost , cost[u.city][i]) )
            {
                v.distance = max(ucost , cost[u.city][i]);
                q.push(v);
                dist[v.city] = v.distance;
            }
        }
    }
}

int main()
{
//    freopen("1.txt","r",stdin);
    int flag,t,test,i,j,k,n,m,l,target;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d",&n,&m);
        init(n);
        FOR(i,m)
        {
            scanf("%d %d %d",&j,&k,&target);

            edge[j].push_back(k);
            edge[k].push_back(j);
            cost[j].push_back(target);
            cost[k].push_back(target);
        }
        scanf("%d",&target);
        dijkstra(target);
        printf("Case %d:\n",++t);
        FOR(i,n)
        {
            if(dist[i] == inf) printf("Impossible\n");
            else printf("%d\n",dist[i]);
        }
    }


    return 0;
}
