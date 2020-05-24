#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SZ 110

int matrix[SZ][SZ] , nodes , cost ,last;
bool col[SZ];

void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++){
        for(j=i+1;j<=n;j++)
            matrix[i][j] = matrix[j][i] = 0;
        col[i] = 0;
    }
}

void dfs(int n)
{
    col[n] = 1;
    int i;
    for(i=1;i<=nodes;i++)
    {
        if(matrix[n][i] > 0 && col[i] == 0) last = i , dfs(i);
    }
    for(i=0;i<=nodes;i++)
    {
        if(matrix[n][i] < 0 && col[i] == 0) last = i , cost += -matrix[n][i] , dfs(i);
    }
}

int main()
{
    int i,j,sum,ans,u,v,w,n,m,t,test;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        nodes = n;
        sum = 0;
        init(n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            sum += w;
            matrix[u][v] = w;
            matrix[v][u] = -w;
        }
        cost = 0;
        dfs(1);
        if(matrix[last][1] < 0) cost += -matrix[last][1];
        ans = sum - cost;
        if(ans > cost) ans = cost;
        printf("Case %d: %d\n",++t,ans);
    }

    return 0;
}
