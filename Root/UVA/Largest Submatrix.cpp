#include <stdio.h>
#include <string.h>

#define SZ 30

char arr[100];
int dp[SZ][SZ] , n;

void solve()
{
    int i,j,k,cnt,maxim;
    for(i=1;i<n;i++)
        for(j=0;j<n;j++)
            if(dp[i][j] == 1)
                dp[i][j] = dp[i][j] + dp[i-1][j];
    maxim = -1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cnt = dp[i][j];
            for(k=j+1;k<n && dp[i][j] <= dp[i][k];k++)
                cnt += dp[i][j];
            for(k=j-1;k>=0 && dp[i][j] <= dp[i][k];k--)
                cnt += dp[i][j];
            if(cnt > maxim)
                maxim = cnt;
        }
    }
    printf("%d\n",maxim);
}

void take_input()
{
    n = 0;
    int i;
    while(gets(arr))
    {
        if(strcmp(arr,"\0") == 0) break;
        for(i=0;i<strlen(arr);i++)
            dp[n][i] = arr[i] == '1' ? 1 : 0;
        n++;
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    getchar();
    getchar();
    while(test--)
    {
        take_input();
        solve();
        if(test) printf("\n");
    }
    return 0;
}
