#include "stdio.h"
#include "string.h"

#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define inf 1<<28
#define SD(n) scanf("%d",&n)
#define SZ 55
#define SZ1 1010
#define mod 100000007

int n , A[SZ] , C[SZ] , dp[SZ][SZ1];

int ways(int amount,int indx)
{
    if(indx == n)
    {
        if(amount == 0) return 1;
        return 0;
    }

    if(amount == 0) return 1;
    if(amount < 0) return 0;
    if(dp[indx][amount] != -1) return dp[indx][amount];

    int i,res = 0;

    for(i=0;i<=C[indx];i++)
    {
        res = (res + ways(amount - A[indx]*i , indx+1)) % mod;
    }
    return dp[indx][amount] = res;
}

int main()
{
    int t,test,target,i,j;
    test = 0;
    SD(t);
    while(t--)
    {
        SD(n);SD(target);
        FOR(i,n) SD(A[i]);
        FOR(i,n) SD(C[i]);
        FOR(i,SZ) FOR(j,SZ1) dp[i][j] = -1;
        printf("Case %d: %d\n",++test,ways(target,0));
    }

    return 0;
}
