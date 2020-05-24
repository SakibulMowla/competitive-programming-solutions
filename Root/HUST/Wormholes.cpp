#include "stdio.h"
#include "iostream"
#include "vector"

using namespace std;

const int inf = 1e9;
#define SZ 510
#define sz(a) (int)a.size()

struct data
{
    int from, to, cost;
    data(){}
    data(int a,int b,int c)
    {
        from = a;
        to = b;
        cost = c;
    }
};

vector <data> adj;
int dist[SZ];

bool Bellman_Ford(int n)
{
    int i, j, k, f;

    dist[1] = 0;

    for(i=1; i<=n; i++)
    {
        f = 1;
        k = sz(adj);
        for(j=0;j<k;j++)
        {
            if(dist[adj[j].to] > dist[adj[j].from] + adj[j].cost)
            {
                dist[adj[j].to] = dist[adj[j].from] + adj[j].cost;
                f = 0;
            }
        }
        if(f)
            break;
    }

    for(j=0;j<k;j++)
        if(dist[adj[j].to] > dist[adj[j].from] + adj[j].cost)
            return true;


    return false;
}

int main()
{
    int t, n, m, q, i, j, k, l;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d %d",&n,&m,&q);

        for(i=0; i<=n; i++)
        {
            dist[i] = inf;
        }
        adj.clear();

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj.push_back( data(j, k, l) );
            adj.push_back( data(k, j, l) );
        }

        for(i=0; i<q; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj.push_back( data(j, k, -l) );
        }

        if(Bellman_Ford(n)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
