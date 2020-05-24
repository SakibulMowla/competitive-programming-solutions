#include "stdio.h"
#include "string.h"
#include "vector"
#include "iostream"

using namespace std;

#define SZ 2010

int col[SZ], low[SZ];
char mark[SZ][SZ], adj[SZ][SZ];
int timer;
int n;

void Tarjan_SCC(int u, int par)
{
//    printf("uu %d %d\n",u,par);
    col[u] = low[u] = timer++;
    int i;

    for(i=1; i<=n; i++)
    {
        if(!adj[u][i]) continue;

        if(!col[i])
        {
            Tarjan_SCC(i, u);
            low[u] = min(low[u], low[i]);

            if(adj[u][i] && adj[i][u])
            {
                if(low[i] <= col[u] && (!mark[u][i]))
                {
                    printf("%d %d %d\n",u,i,1);
                    mark[u][i] = mark[i][u] = 1;
                }
                else if(col[u] < low[i])
                    printf("%d %d %d\n",u,i,2);
            }
        }

        else if(i != par)
        {
            low[u] = min(low[u], col[i]);
            if(adj[u][i] && adj[i][u] && (!mark[u][i]))
            {
                printf("%d %d %d\n",u,i,1);
                mark[u][i] = mark[i][u] = 1;
            }
        }
    }

    return ;
}

int main()
{
    int m, i, j, k, l;

    while(scanf("%d %d",&n,&m) == 2)
    {
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                mark[i][j] = 0, adj[i][j] = 0;

        memset(col, 0, sizeof(int)*(n+2));
//        memset(low, 0, sizeof(int)*(n+2));

        timer = 1;

        for(i=0; i<m; i++)
        {
            scanf("%d %d %d",&j,&k,&l);
            adj[j][k] = 1;
            if(l == 2)
                adj[k][j] = 1;
        }

        Tarjan_SCC(1, -1);
    }

    return 0;
}

