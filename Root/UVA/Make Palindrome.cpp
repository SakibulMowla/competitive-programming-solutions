#include "stdio.h"
#include "string.h"

#define SZ 1010

template <class T> T min(T a,T b) { return a < b ? a : b; }
const int inf = 1<<28;
int dp[SZ][SZ];
char arr[SZ];

int solve(int start,int end)
{
    if(start >= end) return 0;
    int &ret = dp[start][end];
    if(ret != -1) return ret;
    ret = inf;
    if(arr[start] == arr[end]) ret = solve(start+1,end-1);
    else ret = min(solve(start+1,end) , solve(start,end-1)) + 1;
    return ret;
}

void printpath(int start,int end)
{
    if(start == end)
    {
        printf("%c",arr[start]);
        return;
    }
    if(start > end)
        return;
    if(arr[start] == arr[end])
    {
        printf("%c",arr[start]);
        printpath(start+1,end-1);
        printf("%c",arr[start]);
    }
    else if(dp[start+1][end] < dp[start][end-1])
    {
        printf("%c",arr[start]);
        printpath(start+1,end);
        printf("%c",arr[start]);
    }
    else
    {
        printf("%c",arr[end]);
        printpath(start,end-1);
        printf("%c",arr[end]);
    }
}

int main()
{
    int i,j,n;
    while(scanf("%s",arr) == 1)
    {
        n = strlen(arr);
        for(i=0; i<=n; i++) for(j=0; j<=n; j++) dp[i][j] = -1;
        printf("%d ",solve(0,n-1));
        printpath(0,n-1);
        printf("\n");
    }

    return 0;
}
