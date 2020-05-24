#include <bits/stdc++.h>
using namespace  std;

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way

#define SZ 1010
const int inf = 1e9;

int r, c;
char arr[SZ][SZ];
int dist[SZ][SZ];
queue <int> Q;

void ALL_BFS(int s1,int s2)
{
    int i, j, u, v, p, q, k=0;

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            dist[i][j] = inf;
    while(!Q.empty()) Q.pop();
    dist[s1][s2] = 0;
    Q.push(s1);
    Q.push(s2);

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        v = Q.front(); Q.pop();
        for(i=0;i<4;i++)
        {
            p = u + x[i];
            q = v + y[i];
            if(p>=0 && q>=0 && p<r && q<c && dist[p][q] == inf && arr[p][q] != 'T')
            {
                dist[p][q] = dist[u][v] + 1;
                Q.push(p);
                Q.push(q);
            }
        }
    }

    return;
}

int main()
{
    int i, j, k, s1, s2, e1, e2;

    while(scanf("%d %d",&r,&c) == 2)
    {
        for(i=0;i<r;i++)
            scanf(" %s",arr[i]);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                if(arr[i][j] == 'S')
                    s1 = i, s2 = j;
                if(arr[i][j] == 'E')
                    e1 = i, e2 = j;
            }
        ALL_BFS(e1, e2);
        k = 0;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                if(arr[i][j] >= '1' && arr[i][j] <= '9' && dist[i][j] <= dist[s1][s2])
                    k += arr[i][j] - '0';
        printf("%d\n",k);
    }

    return 0;
}
