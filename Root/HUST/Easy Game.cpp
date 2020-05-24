#include "stdio.h"
#define SZ 110

int n , arr[SZ] , dp[SZ][SZ] , sum[SZ][SZ] ;
const int inf = 1<<28;
template <class T> T max(T a,T b) { return a > b ? a : b; }

void cumulative()
{
    int i,j;
    for(i=0; i<n; i++)
        for(j=i; j<n; j++)
        {
            if(i == j) sum[i][j] = arr[j];
            else sum[i][j] = sum[i][j-1] + arr[j];
        }
}

int solve(int start,int end)
{
    if(start > end) return 0;
    int &ret = dp[start][end];
    if(ret != -1) return ret;
    ret = -inf;
    int i;
    for(i=start;i<=end;i++)
    {
        ret = max(ret , sum[start][i]-solve(i+1,end));
    }
    for(i=end;i>=start;i--)
    {
        ret = max(ret , sum[i][end]-solve(start,i-1));
    }
    return ret;
}

int main()
{
    int t=0,test,i,j;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++) scanf("%d",&arr[i]);
        for(i=0; i<=n; i++) for(j=0; j<=n; j++) dp[i][j] = -1;
        cumulative();
        printf("Case %d: %d\n",++t,solve(0,n-1));
    }

    return 0;
}
