#include <stdio.h>
#include <string.h>
#include <math.h>

#define SZ 110
#define inf 1<<28
#define min(a,b) a<b ? a : b

struct data {int x,y,r;};

int main()
{
    data arr[SZ];
    int i,j,k,speed,day,n,matrix[SZ][SZ];
    double dist;
    while(scanf("%d %d",&day,&speed) == 2)
    {
        scanf("%d %d %d",&arr[0].x,&arr[0].y,&arr[0].r);
        scanf("%d %d %d",&arr[1].x,&arr[1].y,&arr[1].r);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&arr[i+2].x,&arr[i+2].y,&arr[i+2].r);
        }
        for(i=0;i<n+2;i++)
        {
            for(j=i+1;j<n+2;j++)
                matrix[i][j] = matrix[j][i] = inf;
            matrix[i][i] = 0;
        }
        for(i=0;i<n+2;i++)
        {
            for(j=i+1;j<n+2;j++)
            {
                dist = sqrt(pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2)) - (arr[i].r + arr[j].r);
                dist /= speed;
                if(dist <= day)
                    matrix[i][j] = matrix[j][i] = 1;
            }
        }
        for(k=0;k<n+2;k++)
            for(i=0;i<n+2;i++)
                for(j=0;j<n+2;j++)
                    matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        if(matrix[0][1] < inf)
            printf("Larry and Ryan will escape!\n");
        else
            printf("Larry and Ryan will be eaten to death.\n");
    }

    return 0;
}
