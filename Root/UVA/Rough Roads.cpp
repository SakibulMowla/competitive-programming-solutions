#include "stdio.h"
#include "string.h"
#include "vector"
#include "queue"
#include "iostream"

using namespace std;

#define SZ 510
#define MP(a,b) make_pair(a,b)

typedef pair<int,int>pii;
vector <pii> adj[SZ];
const int inf = 1e9;

int n, dist[SZ][2];
bool rep[SZ][2];

queue <int> Q;

int bfs()
{
    while(!Q.empty()) Q.pop();
    int i, j, p, q, u, v, k;

    Q.push(0);
    Q.push(0);
    dist[0][0] = 0;

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();
        rep[u][v] = 0;
        k = adj[u].size();
        for(i=0; i<k; i++)
        {
            p = adj[u][i].first;
            q = adj[u][i].second;
            if(dist[p][!v] > dist[u][v] + q)
            {
                dist[p][!v] = dist[u][v] + q;
                if(rep[p][!v] == 0)
                {
                    rep[p][!v] = 1;
                    Q.push(p);
                    Q.push(!v);
                }
            }
        }
    }
    return dist[n-1][0];
}

int main()
{
    int i, r, x, y, z, test=0;

    while(scanf("%d %d",&n,&r) == 2)
    {
        for(i=0; i<n; i++)
        {
            dist[i][0] = dist[i][1] = inf;
            rep[i][0] = rep[i][1] = 0;
            adj[i].clear();
        }
        for(i=0; i<r; i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            adj[x].push_back(MP(y,z));
            adj[y].push_back(MP(x,z));
        }
        printf("Set #%d\n",++test);
        z = bfs();
        if(z >= inf)    printf("?\n");
        else printf("%d\n",z);
    }

    return 0;
}
