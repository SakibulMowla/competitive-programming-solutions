using namespace std;

#include "stdio.h"
#include "vector"
#include "iostream"

#define MAX 1000100

vector <int> adj[MAX];
int Q[MAX], indeg[MAX], n, m, node;

void BFS_topsort()
{
    int i=0, j, k, u, v;

    while(i != node)
    {
        u = Q[i++];
        k = adj[u].size();

        for(j=0; j<k; j++)
        {
            v = adj[u][j];
            indeg[v]--;
            if(indeg[v] == 0)
                Q[node++] = v;
        }
    }
}

int main()
{
    int a, b, i;

    while(scanf("%d %d",&n,&m))
    {
        if(n == 0 && m == 0)
            break;
        for(i=1; i<=n; i++)
            adj[i].clear(), indeg[i] = 0;

        for(i=0; i<m; i++)
        {
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            indeg[b]++;
        }

        node = 0;

        for(i=1; i<=n; i++)
        {
            if(indeg[i] == 0)
                Q[node++] = i;
        }

        BFS_topsort();

        if(node != n)   printf("IMPOSSIBLE\n");
        else
            for(i=0; i<n; i++)
                printf("%d\n",Q[i]);
    }

    return 0;
}
