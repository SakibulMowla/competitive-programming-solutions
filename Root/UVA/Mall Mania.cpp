#include "bits/stdc++.h"
using namespace std;

#define SZ 2010

int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};

int dist[SZ][SZ], mall[SZ][SZ];
queue <int> Q;

int bfs()
{
    int i, u, v, a, b;

    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        b = Q.front();
        Q.pop();

        if(mall[a][b] == 2)
        {
            return dist[a][b];
        }

        for(i=0; i<4; i++)
        {
            u = a + x[i];
            v = b + y[i];
            if(u >= 0 && u <= 2000 && v >= 0 && v <= 2000 && dist[u][v] == -1)
            {
                dist[u][v] = dist[a][b] + 1;
                if(mall[u][v] == 2)
                {
                    return dist[u][v];
                }
                Q.push(u);
                Q.push(v);
            }
        }
    }
}


int main()
{
    int i, j, k, n, m;

    while(~scanf("%d",&n) && n)
    {
        memset(dist, -1, sizeof(dist));
        memset(mall, -1, sizeof(mall));
        while(!Q.empty())
            Q.pop();

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&j,&k);
            dist[j][k] = 0;
            Q.push(j);
            Q.push(k);
        }

        scanf("%d",&m);

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&j,&k);
            mall[j][k] = 2;
        }

        printf("%d\n",bfs());
    }

    return 0;
}
