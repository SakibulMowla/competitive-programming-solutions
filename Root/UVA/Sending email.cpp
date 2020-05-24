#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

vector <int> edge[20010],cost[20010];
int dist[20010];
const int inf = 1000000000;
int n,m;

struct data
{
    int city, dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

int dijkstra(int source,int target)
{
    for(int i=0;i<n;i++)
        dist[i] = inf;

    priority_queue <data> q;
    data u,v;
    u.city = source;
    u.dist = 0;
    q.push(u);
    dist[source] = 0;

    while( !q.empty() )
    {
        u = q.top();
        q.pop();
        int ucost = dist[u.city];

        for(int i=0;i<edge[u.city].size();i++)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + ucost;
            if(dist[v.city] > v.dist)
            {
                dist[v.city] = v.dist;
                q.push(v);
            }
        }
    }

    return dist[target];
}

int main()
{
    int i,j,res,test,s,t,node1,node2,costt;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d %d %d %d",&n,&m,&s,&t);

        for(j=0;j<m;j++)
        {
            scanf("%d %d %d",&node1,&node2,&costt);
            edge[node1].push_back(node2);
            edge[node2].push_back(node1);
            cost[node1].push_back(costt);
            cost[node2].push_back(costt);
        }
        res = dijkstra(s,t);
        if(res == inf)
            printf("Case #%d: unreachable\n",i);
        else
            printf("Case #%d: %d\n",i,res);
        for(j=0;j<n;j++)
        {
            edge[j].clear();
            cost[j].clear();
        }
    }

    return 0;
}
