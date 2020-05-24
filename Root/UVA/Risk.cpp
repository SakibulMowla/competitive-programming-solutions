#include <stdio.h>
#include <string.h>

#define max 100
#define min(a,b) a<b?a:b
#define inf 999999999

int matrix[max][max];

void floyd_warshall(int n)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                matrix[i][j]=min( matrix[i][j] , matrix[i][k] + matrix[k][j]);
    return;
}

int main()
{
    int i,j,t,n,temp,test,node,start,target;
    test=0;
    while(scanf("%d",&t) == 1)
    {
        for(i=1;i<=20;i++)
            for(j=i+1;j<=20;j++)
                matrix[i][j] = matrix[j][i] = inf;
        matrix[0][0]=0;
        for(i=1;i<=t;i++)
        {
            scanf("%d",&node);
            matrix[1][node]=1;
            matrix[node][1]=1;
        }

        for(i=2;i<=19;i++)
        {
            scanf("%d",&t);
            for(j=1;j<=t;j++)
            {
                scanf("%d",&node);
                matrix[i][node]=1;
                matrix[node][i]=1;
            }
        }

        floyd_warshall(20);

        scanf("%d",&n);
        printf("Test Set #%d\n",++test);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&start,&target);
            printf("%2d to %2d: %d\n",start,target,matrix[start][target]);
        }
        printf("\n");
    }
    return 0;
}
