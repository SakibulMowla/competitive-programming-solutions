#include <stdio.h>
#include <math.h>

#define max 15

int arr[15][15];
int row,col,sum;

int dfs(int n,int m)
{
    if(row<0 || col<0 || n>=row || m>=col)return;

    int i,j,t;

    for(i=n,t=0; i<row && t<2 && i!=row ; i=col-1,t++)
    {
        if(t==1 && i==n) break;
        for(j=m; j<col; j++)
        {
            sum+=arr[i][j];
        }
    }

    for(j=m,t=0; j<col && t<2 ; j=row-1,t++)
    {
        for(i=n+1; i<row-1; i++)
        {
            sum+=arr[i][j];
        }
    }

    row-=1;
    col-=1;
    printf(" %d",sum);
    sum=0;
    dfs(n+1,m+1);
    return;
}

int main()
{
    int t,n,m,i,j,k,l;
    t=0;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&arr[i][j]);

        row=col=n;
        sum=0;
        printf("Case %d:",++t);
        dfs(0,0);
        printf("\n");
    }
    return 0;
}
