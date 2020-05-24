#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define SZ 110
int max(int a,int b)
{
    return (a>b)?a:b;
}
int min(int a,int b)
{
    return  (a<b)?a:b;
}
#define inf 200000

int matrix[SZ][SZ];

int main()
{
    int s,d,i,j,k,trip,test=0,n,r,passengers,gang,a,b,c;
    while(scanf("%d %d",&n,&r) == 2)
    {
        if(n==0 && r==0)break;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
                matrix[i][j] =  -inf;
            matrix[i][i] = 0;
        }

        for(i=1; i<=r; i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            matrix[a][b] = matrix[b][a] = c;
        }

        for(k=1; k<=n; k++)
            for(i=1; i<=n; i++)
                for(j=1; j<=n; j++)
                    matrix[i][j] = max( matrix[i][j] , min( matrix[i][k] , matrix[k][j] ) );


        scanf("%d %d %d",&s,&d,&gang);

        trip = ceil(gang * 1.0 / (matrix[s][d]-1));

        printf("Scenario #%d\n",++test);
        printf("Minimum Number of Trips = %d\n\n",trip);
    }

    return 0;
}
