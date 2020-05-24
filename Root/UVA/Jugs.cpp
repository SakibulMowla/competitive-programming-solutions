#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

#define SZ 1010
#define inf 1<<28

char arr[10][20] = {"fill A","fill B","empty A","empty B","pour A B","pour B A"};
enum {fillA,fillB,emptyA,emptyB,pourAB,pourBA};
struct data {int x,y;};

int dist[SZ][SZ] , job[SZ][SZ] , ca ,cb , n;
data par[SZ][SZ];

queue <data> Q;


void init()
{
    while( !Q.empty() ) Q.pop();
    int i,j;
    for(i=0;i<SZ;i++)
        for(j=0;j<SZ;j++)
            dist[i][j] = inf;
}

void print(int a,int b)
{
    if(a+b == 0) return;
    print(par[a][b].x , par[a][b].y);
    printf("%s\n",arr[ job[a][b] ]);
}


void bfs()
{
    data u,v;
    int a;
    u.x = 0 , u.y = 0;
    dist[0][0] = 0;
    Q.push(u);

    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();

        if(u.y == n) break;

        a = dist[u.x][u.y] + 1;

        // filling A
        v.x = ca;
        v.y = u.y;

        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = fillA;
        }

        // filling B
        v.x = u.x;
        v.y = cb;

        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = fillB;
        }

        //empting A
        v.x = 0;
        v.y = u.y;

        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = emptyA;
        }

        // empting B
        v.x = u.x;
        v.y = 0;
        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = emptyB;
        }

        // pour  A --> B
        if(u.x + u.y >= cb)
            v.x = u.x - ( cb - u.y ) , v.y = cb;
        else
            v.x = 0 , v.y = u.y + u.x;

        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = pourAB;
        }

        // pour B -- > A
        if(u.x + u.y >= ca)
            v.x = ca , v.y = u.y - (ca - u.x);
        else
            v.x = u.x + u.y , v.y = 0;

        if(dist[v.x][v.y] > a)
        {
            dist[v.x][v.y] = a;
            Q.push(v);
            par[v.x][v.y] = u;
            job[v.x][v.y] = pourBA;
        }
    }

    print(u.x,u.y);
    printf("success\n");

}


int main()
{
    while(scanf("%d %d %d",&ca,&cb,&n) == 3)
    {
        init();
        bfs();
    }
    return 0;
}
