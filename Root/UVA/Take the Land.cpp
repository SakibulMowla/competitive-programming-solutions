#include <stdio.h>
#include <string.h>

#define SZ 110

int dp[SZ][SZ];

void solve(int r,int c)
{
    int i,j,k,cnt,maxim;
    for(i=1; i<r; i++)
        for(j=0; j<c; j++)
            if(dp[i][j] == 1)
                dp[i][j] = dp[i][j] + dp[i-1][j];
    maxim = -1;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            cnt = dp[i][j];
            for(k=j+1;k<c && dp[i][j] <= dp[i][k];k++)
                cnt += dp[i][j];
            for(k=j-1;k>=0 && dp[i][j] <= dp[i][k];k--)
                cnt += dp[i][j];
            if(cnt > maxim)
                maxim = cnt;
        }
    }
    printf("%d\n",maxim);
}

void take_input(int r,int c)
{
    int i,j,val;
    for(i=0; i<r; i++)
        for(j=0; j<c; j++)
        {
            scanf("%d",&val);
            if(val == 0)
                dp[i][j] = 1;
            else dp[i][j] = 0;
        }
}

int main()
{
    int r,c;
    freopen("1.txt","r",stdin);
    while(scanf("%d %d",&r,&c) == 2)
    {
        if(r == 0 && c == 0)break;
        take_input(r,c);
        solve(r,c);
    }

    return 0;
}
