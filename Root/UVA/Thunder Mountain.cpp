            // 10803 - Thunder Mountain
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define FOR(a,b) for(a=0;a<b;a++)
#define min(a,b) a < b ? a : b

struct data
{
    int x,y;
}arr[110];

const int inf = INT_MAX;

int main()
{
    int n,i,j,k,t,test;
    double d,matrix[110][110];
    scanf("%d",&test);
    for(t=1; t<=test; t++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
            scanf("%d %d",&arr[i].x,&arr[i].y);
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                d = sqrt( pow(arr[i].x-arr[j].x , 2) + pow(arr[i].y-arr[j].y , 2) );
                if(d > 10.00)
                    d = inf;
                matrix[i][j] = matrix[j][i] = d;
            }
            matrix[i][i] = 0;
        }
        FOR(k,n)FOR(i,n)FOR(j,n) matrix[i][j] = min(matrix[i][j] , matrix[i][k] + matrix[k][j]);
        d = 0;
        for(i=0; i<n; i++)
            for(j=i+1; j<n; j++)
                if(matrix[i][j] > d)
                    d = matrix[i][j];
        printf("Case #%d:\n",t);
        if(d == inf)
            printf("Send Kurdy\n");
        else
            printf("%.4lf\n",d);
        printf("\n");
    }

    return 0;
}
