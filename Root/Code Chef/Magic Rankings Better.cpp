#include "stdio.h"

#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define inf 1<<28
#define SD(a) scanf("%d",&a)
#define SZ 110

int max(int a,int b){ return a > b ? a : b; };

int s[SZ][SZ] ,dp[SZ][SZ];

int main()
{
    int i,j,n,t;
    FOR(i,SZ) dp[0][i] = dp[i][0] = -inf;
    SD(t);
    while(t--)
    {
        SD(n);
        FORI(i,1,n) FORI(j,1,n)
        {
            SD(s[i][j]);
            if(i+j == 2) dp[i][j] = s[i][j];
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) + s[i][j];
        }
        if(dp[n][n] < 0) printf("Bad Judges\n");
        else printf("%.10lf\n",(double)dp[n][n] / (2*n-3));
    }

    return 0;
}
