#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

using namespace  std;

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way

#define SZ 510

char arr[SZ][SZ];
bool col[SZ][SZ];
int r, c, tot;

struct data
{
    int x, y;
    char ch;
};

data info[SZ*SZ*3];

void dfs(int n, int m,int k)
{
    col[n][m] = 1;
    info[tot].ch = 'B';
    info[tot].x = n+1;
    info[tot++].y = m+1;
    int i, u, v;
    for(i=0; i<4; i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u >=0 && v >= 0 && u < r && v < c && arr[u][v] == '.' && col[u][v] == 0)
            dfs(u, v, 1);
    }
    if(k == 1)
    {
        info[tot].ch = 'D';
        info[tot].x = n+1;
        info[tot++].y = m+1;
        info[tot].ch = 'R';
        info[tot].x = n+1;
        info[tot++].y = m+1;
    }
}

//%I64d
int main()
{
    int  i, j;

    while(scanf("%d %d",&r, &c) == 2)
    {
        for(i=0; i<r; i++)
            scanf(" %s",arr[i]);
        tot = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                if(arr[i][j] == '.' && col[i][j] == 0)
                    dfs(i, j, 0);
        printf("%d\n", tot);
        for(i=0;i<tot;i++)
            printf("%c %d %d\n",info[i].ch,info[i].x,info[i].y);
    }

    return 0;
}
