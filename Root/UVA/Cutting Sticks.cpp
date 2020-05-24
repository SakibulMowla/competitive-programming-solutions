#include "stdio.h"
#include "string.h"

#define SZ 55

template <class T> T min(T a,T b) { return a < b ? a : b; }
const int inf = 1<<28;
int dp[SZ][SZ] , arr[SZ];

int solve(int start,int end)
{
    if(start+1 == end) return 0;

    int i, tmp , &ret = dp[start][end];
    if(ret != -1) return ret;

    ret = inf;
    tmp = arr[end] - arr[start];

    for(i=start+1;i<end;i++)
        ret = min(ret , solve(start,i)+solve(i,end)+tmp);

    return ret;
}

int main()
{
    int i,j,l,n;
    while(scanf("%d",&l) == 1 && l)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&arr[i]);
        n++;
        arr[n] = l;
        for(i=0;i<=n;i++)
            for(j=i;j<=n;j++)
                dp[i][j] = -1;
        printf("The minimum cutting is %d.\n",solve(0,n));
    }
    return 0;
}
