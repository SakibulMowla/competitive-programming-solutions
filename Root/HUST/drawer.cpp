#include "stdio.h"
#include "string.h"
#include "string"
#include "vector"
#include "map"
#include "math.h"
#include "queue"
#include "stack"
#include "algorithm"
#include "iostream"

using namespace std;

#define inf 1<<28
#define SZ 70

long long dp[SZ][SZ][3] ,n ,s;

long long solve(long long n1,long long s1,long long con)
{
    if(s1 > s) return 0;
    if(n1 == n)
    {
        if(s1 == s) return 1;
        return 0;
    }
    if(dp[n1][s1][con] != -1) return dp[n1][s1][con];
    long long k=0;
    k += solve(n1+1,s1,0);
    if(con == 1) k += solve(n1+1,s1+1,1);
    else k += solve(n1+1,s1,1);
    return dp[n1][s1][con] = k;
}

int main()
{
    while(scanf("%lld %lld",&n,&s) == 2)
    {
        if(n+s<0) break;
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(0,0,1));
    }

    return 0;
}
