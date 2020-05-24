#include "stdio.h"

#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SLLD(n) scanf("%lld",&n)
#define SZ 210
#define LL long long
LL max(LL a,LL b){ return a > b ? a : b ; }

LL banana[SZ][SZ] , dp[SZ][SZ] , row , col;

LL solve(LL i,LL j)
{
    if(i > row || j > col) return 0;
    if(banana[i][j] == -1) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    return dp[i][j] = max(solve(i+1,j) , solve(i+1,j+1)) + banana[i][j];
}

int main()
{
    LL t=0,test,n,i,j,k;
    SLLD(test);
    while(test--)
    {
        SLLD(n);
        row = 2*n - 1;
        col = n;
        FORI(i,0,row) FORI(j,0,col) dp[i][j] = banana[i][j] = -1;
        FORI(i,1,n) FORI(j,1,i) SLLD(banana[i][j]);
        k = 1;
        FORI(i,n+1,row) FORI(j,++k,n) SLLD(banana[i][j]);
        printf("Case %lld: %lld\n",++t,solve(1,1));
    }

    return 0;
}
