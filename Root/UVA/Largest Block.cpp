#include <stdio.h>
#include <string.h>

#define SZ 110

int dp[SZ][SZ];
int n;

void solve()
{
    int i,j,k,cnt,maxim;
    for(i=2;i<=n;i++)
        for(j=1;j<=n;j++)
            if(dp[i][j] == 1)
                dp[i][j] = dp[i][j] + dp[i-1][j];
    maxim = -1;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            cnt = dp[i][j];
            for(k=j+1;k<=n && dp[i][j] <= dp[i][k];k++)
                cnt += dp[i][j];
            for(k=j-1;k>=0 && dp[i][j] <= dp[i][k];k--)
                cnt += dp[i][j];
            if(cnt > maxim)
                maxim = cnt;
        }
    printf("%d\n",maxim);
}

void take_input()
{
    int i,j,blocks,r1,c1,r2,c2;
    scanf("%d %d",&n,&blocks);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dp[i][j] = 1;
    while(blocks--)
    {
        scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
        for(i=r1;i<=r2;i++)
            for(j=c1;j<=c2;j++)
                dp[i][j] = 0;
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        take_input();
        solve();
    }
    return 0;
}
