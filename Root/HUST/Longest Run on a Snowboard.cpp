#include "stdio.h"
#include "string.h"

#define SZ 110

int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};

int arr[SZ][SZ] , col[SZ][SZ] , r , c;

int dfs(int n,int m)
{
    if(col[n][m] != -1) return col[n][m];
    int i,u,v,p;
    p = 0;
    for(i=0;i<4;i++)
    {
        u = n + x[i];
        v = m + y[i];
        if(u>=0 && v>=0 && u<r && v<c && arr[u][v] < arr[n][m])
        {
            if(dfs(u,v) > p )
                p = dfs(u,v);
        }
    }
    return col[n][m] = p + 1;
}

int main()
{
    int test,i,j,maxim;
    char str[SZ];
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %s %d %d",str,&r,&c);
        for(i=0;i<r;i++) for(j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            col[i][j] = -1;
        }
        maxim = -1;
        for(i=0;i<r;i++) for(j=0;j<c;j++)
            if(dfs(i,j) > maxim)
                maxim = dfs(i,j);
        printf("%s: %d\n",str,maxim);
    }

    return 0;
}
