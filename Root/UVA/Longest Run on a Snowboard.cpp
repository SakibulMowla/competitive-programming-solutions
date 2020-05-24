#include <stdio.h>
#include <string.h>

#define SZ 110

int x[] = {-1 , 1 , 0 , 0};
int y[] = {0 , 0 , -1 , 1};

int arr[SZ][SZ] , dp[SZ][SZ] , r , c;

int dfs(int i,int j)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    int n,m,a,maxim=0;
    for(a=0;a<4;a++)
    {
        n = i + x[a];
        m = j + y[a];
        if(n>=0 && m>=0 && n<r && m<c && arr[n][m] < arr[i][j])
        {
            if(dfs(n,m) > maxim)
                maxim = dfs(n,m);
        }
    }
    return dp[i][j] = 1 + maxim;
}

int main()
{
    int test,i,j,maxim;
    char str[SZ];
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %s %d %d",str,&r,&c);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                scanf("%d",&arr[i][j]);
                dp[i][j] = -1;
            }
        maxim = -1;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                if(dfs(i,j) > maxim)
                    maxim = dfs(i,j);
            }
        }
        printf("%s: %d\n",str,maxim);
    }

    return 0;
}
