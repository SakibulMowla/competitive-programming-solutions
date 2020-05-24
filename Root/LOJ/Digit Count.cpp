#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define SZ 12

int dp[SZ][SZ] , digit[SZ] , n , m;

int solve(int indx,int last_digit)
{
    if(indx == n) return 1;
    int &ret = dp[indx][last_digit];
    if(ret != -1) return ret;
    int i;
    ret = 0;
    if(indx == 0)
        for(i=0;i<m;i++)
            ret += solve(indx+1,digit[i]);
    else
        for(i=0;i<m;i++)
            if(abs(digit[i]-last_digit) <= 2)
                ret += solve(indx+1,digit[i]);
    return ret;
}

int main()
{
    int t=0,test,i;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%d %d",&m,&n);
        for(i=0;i<m;i++) scanf("%d",&digit[i]);
        memset(dp,-1,sizeof(dp));
        printf("Case %d: %d\n",++t,solve(0,0));
    }

    return 0;
}
