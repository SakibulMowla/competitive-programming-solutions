#include <stdio.h>
#include <string.h>

#define inf 1<<28

#define min(a,b) a<b?a:b

int main()
{
    int n,m,i,j,k,cost,t=0,mincost,node;
    char arr[110][20];
    int matrix[110][110];
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(n+m==0)break;
        for(i=1;i<=n;i++)
            scanf("%s",arr[i]);
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] =0;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&j,&k,&cost);
            matrix[j][k] = matrix[k][j] = cost;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        node = 1;
        mincost = inf;
        for(i=1;i<=n;i++)
        {
            cost  = 0;
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                    cost += matrix[i][j];
            }
            if(cost < mincost)
            {
                mincost = cost;
                node = i;
            }
        }
        printf("Case #%d : %s\n",++t,arr[node]);
    }

    return 0;
}
