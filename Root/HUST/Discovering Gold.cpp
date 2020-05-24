#include "stdio.h"
#include "string.h"
#include "math.h"

#define SZ 110

double dp[SZ] , arr[SZ];
int N;

double solve(int n)
{
//    printf("n = %d N = %d\n",n,N);
    if(n >= N) return 0;
    if(dp[n] != -1.0) return dp[n];
    double num,ans=arr[n];
    int i;
    num = N - n - 1;
    if(num > 6) num = 6;
    for(i=1;i<=num;i++)
        ans += (1/num)*(solve(n+i));
    return dp[n] = ans;
}

int main()
{
    int t=0,test,i;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++) scanf("%lf",&arr[i]);
        for(i=0;i<N;i++) dp[i] = -1.0;
        printf("Case %d: %.8lf\n",++t,solve(0));
    }

    return 0;
}
