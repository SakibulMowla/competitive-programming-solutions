#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"
using namespace std;
#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SZ 1010

vector <int> edge[SZ] , cost[SZ];
int dist[SZ];

bool bellman_ford(int node)
{
    int i,j,k;
    dist[0] = 0;
    FOR(i,node) FOR(j,edge[i].size())
    if(dist[i] + cost[i][j] < dist[ edge[i][j] ]) dist[ edge[i][j] ] = dist[i] + cost[i][j];
    FOR(i,node) FOR(j,edge[i].size())
    if(dist[i] + cost[i][j] < dist[ edge[i][j] ]) return 1;
    return 0;
}

int main()
{
    int t,n,m,i,strt,trgt,cst;
    SD(t);
    while(t--)
    {
        SD(n);SD(m);
        FOR(i,m)
        {
            SD(strt);SD(trgt);SD(cst);
            edge[strt].push_back(trgt);
            cost[strt].push_back(cst);
        }
        FOR(i,n) dist[i] = inf;
        if(bellman_ford(n)) printf("possible\n");
        else printf("not possible\n");
        FOR(i,n) edge[i].clear() , cost[i].clear();
    }
    return 0;
}
