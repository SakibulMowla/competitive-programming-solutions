#include <stdio.h>
#include <string.h>

#define inf 1000000000

int main()
{
    int test,i,j,k,t,m,n,p,matrix[100][100],start,target,shipment;
    char arr[100][100],node1[100],node2[100];
    scanf("%d",&test);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(t=1;t<=test;t++)
    {
        scanf("%d %d %d",&m,&n,&p);
        for(i=0;i<=m;i++)
            for(j=0;j<=m;j++)
                matrix[i][j]=inf;
        for(i=1;i<=m;i++)
            scanf("%s",arr[i]);
        for(i=1;i<=n;i++)
        {
            scanf("%s %s",node1,node2);
            for(j=1;j<=m;j++)
            {
                if(strcmp(arr[j],node1) == 0)start=j;
                if(strcmp(arr[j],node2) == 0)target=j;
            }
            matrix[start][target]=1;
            matrix[target][start]=1;
        }
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            {
                for(k=1;k<=m;k++)
                {
                    if(matrix[i][j] + matrix[j][k] < matrix[i][k])
                        matrix[k][i]=matrix[i][k] = matrix[i][j] + matrix[j][k];
                }
            }
        }
        for(i=0;i<p;i++)
        {
            scanf("%d %s %s",&shipment,node1,node2);
            flag1=flag2=0;
            for(j=1;j<=m;j++)
            {
                if(strcmp(arr[j],node1) == 0)start=j;
                if(strcmp(arr[j],node2) == 0)target=j;
            }
            if(i==0)
                printf("\nDATA SET  %d\n\n",t);
            if(matrix[start][target] == inf)
                printf("NO SHIPMENT POSSIBLE\n");
            else if(start==target)
                printf("$0\n");
            else
                printf("$%d\n",matrix[start][target]*shipment*100);
        }
        if(t==test)
            printf("\nEND OF OUTPUT\n");
    }
    return 0;
}
