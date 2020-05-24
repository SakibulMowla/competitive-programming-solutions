#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 110

int dp[SZ][SZ];
char arr[SZ];

bool equal(int i, int j)
{
    return (arr[i] == '(' && arr[j] == ')') || (arr[i] == '[' && arr[j] == ']');
}

int solve(int start, int end)
{
    if(start >= end)
        return 0;
    int &ret = dp[start][end];
    if(ret != -1) return ret;
    int i;
    for(i=start; i<end; i++)
        ret = max(ret, solve(start, i) + solve(i+1, end));
    if(equal(start, end)) ret = max(ret, 2+solve(start+1, end-1));
    return ret;
}

int main()
{
    while(scanf("%s",arr+1) == 1)
    {
        if(strcmp(arr+1,"end") == 0)
            break;
        memset(dp, -1, sizeof(dp));
        printf("%d\n",solve(1, strlen(arr+1)));
    }

    return 0;
}
