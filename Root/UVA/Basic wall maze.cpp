#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <iostream>

using namespace std;

#define SZ 7

struct data {int x,y;};

data from[SZ][SZ];
int invalid[SZ][SZ][SZ][SZ];
char par[SZ][SZ];
int color[SZ][SZ];
char arr[6] = {'N' , 'S' , 'W' , 'E'};

queue <int> Q;

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

void bfs(int s1,int s2,int t1,int t2)
{
    while( !Q.empty() ) Q.pop();
    memset(color,0,sizeof(color));
    memset(from,0,sizeof(from));
    memset(par,0,sizeof(par));
    Q.push(s1) , Q.push(s2);
    color[s1][s2] = 1;
    int a,b,u,v,i;
    data d;

    while( !Q.empty() )
    {
        a = Q.front() , Q.pop();
        b = Q.front() , Q.pop();
        d.x = a , d.y = b;
        if(a == t1 && b == t2) break;
        for(i=0;i<4;i++)
        {
            u = a + x[i];
            v = b + y[i];
            if(u>=1 && v>=1 && u<=6 && v<=6 && !color[u][v] && !invalid[a][b][u][v])
            {
                Q.push(u) , Q.push(v);
                color[u][v] = 1;
                from[u][v] = d;
                par[u][v] = arr[i];
            }
        }
    }
}

void wall_maker(int r1,int c1,int r2,int c2)
{
    int i,j;
    if(r1 == r2)
    {
        for(i=c1+1;i<=c2;i++)
        {
            if(r1>=1 && r1<=5)
                invalid[r1][i][r1+1][i] = invalid[r1+1][i][r1][i] = 1;
        }
    }
    else if(c1 == c2)
    {
        for(i=r1+1;i<=r2;i++)
        {
            if(c1>=1 && c1<=5)
                invalid[i][c1][i][c1+1] = invalid[i][c1+1][i][c1] = 1;
        }
    }
}

void print(int s1,int s2,int t1,int t2)
{
    if(s1==t1 && s2==t2)
        return;
    print(s1,s2,from[t1][t2].x,from[t1][t2].y);
    printf("%c",par[t1][t2]);
}

int main()
{
    int s1,t1,s2,t2,r1,r2,c1,c2,i;
    while(scanf("%d %d",&s2,&s1) == 2)
    {
        if(s1+s2 == 0) break;
        scanf("%d %d",&t2,&t1);
        memset(invalid,0,sizeof(invalid));
        for(i=0;i<3;i++)
        {
            scanf("%d %d %d %d",&c1,&r1,&c2,&r2);
            wall_maker(r1,c1,r2,c2);
        }
        bfs(s1,s2,t1,t2);
        print(s1,s2,t1,t2);
        printf("\n");
    }

    return 0;
}
