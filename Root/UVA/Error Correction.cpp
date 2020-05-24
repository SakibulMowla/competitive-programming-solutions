#include "stdio.h"
#define SZ 110
int matrix[SZ][SZ] , rows , cols , n , x , y;

void solve()
{
    rows = cols = 0;
    int i,j,k,sum;
    for(i=1;i<=n;i++)
    {
        sum = 0;
        for(j=1;j<=n;j++)
            sum += matrix[i][j];
        if(sum % 2 == 1)
        {
            rows++;
            x = i;
        }
    }
    for(i=1;i<=n;i++)
    {
        sum = 0;
        for(j=1;j<=n;j++)
            sum += matrix[j][i];
        if(sum % 2 == 1)
        {
            cols++;
            y = i;
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n) == 1 && n)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&matrix[i][j]);
        solve();
        if(rows + cols == 0) printf("OK\n");
        else if(rows == 1 &&  cols == 1) printf("Change bit (%d,%d)\n",x,y);
        else printf("Corrupt\n");
    }

    return 0;
}
