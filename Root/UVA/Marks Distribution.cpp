#include "stdio.h"
#include "math.h"

int n,t,p,low,high;
int dp[75][75];

int backtrack(int sum,int sub)
{
    if(sum==t && sub==n)return 1;
    if(sum>t || sub>=n)return 0;
    if(dp[sum][sub] != -1)return dp[sum][sub];
    int i,ans=0;
    for(i=low;i<=high;i++)
    {
        sum += i;
        ans += backtrack(sum,sub+1);
        sum -= i;
    }
    return dp[sum][sub] = ans;
}

int main()
{
    int test,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d %d %d",&n,&t,&p);
        for(i=0;i<=t;i++)
            for(j=0;j<=n;j++)
                dp[i][j] = -1;
        low = p;
        high = t - p*(n-1);
        printf("%d\n",backtrack(0,0));
    }

    return 0;
}
