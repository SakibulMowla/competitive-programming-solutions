#include "stdio.h"
#include "string.h"
#define SZ 1010

int dp[SZ][SZ];
char arr[1010];
const int inf = 1<<28;
int min(int a,int b) { return a < b ? a : b; }

int solve(int start,int end)
{
    if(start >= end) return 0;
    int &ret = dp[start][end];
    if(ret != -1) return ret;
    ret = inf;
    if(arr[start] == arr[end])
        ret = solve(start+1,end-1);
    else
    {
        ret =  min(ret , 1 + min(solve(start+1,end) , solve(start,end-1)));
        ret =  min(ret ,1 + solve(start+1,end-1));
    }
    return ret;
}

int main()
{
    int t=0,test,i,j,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j] = -1;
        printf("Case %d: %d\n",++t,solve(0,n-1));
    }

    return 0;
}
