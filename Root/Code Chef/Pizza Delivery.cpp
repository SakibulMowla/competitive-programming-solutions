// O( n * max(2 * h[i]) )

#include "stdio.h"
#include "string.h"
#include "math.h"

#define inf 1<<28
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)
#define SD(a) scanf("%d",&a)
#define SZ 1010
#define min(a,b) a < b ? a : b

int dp[SZ/2][SZ] , h[SZ/2] , k[SZ/2];

int main()
{
    int n,i,j,maxim,res,t;
    SD(t);
    while(t--)
    {
        maxim = -1;
        SD(n);
        FORI(i,1,n) SD(h[i]) , maxim = (h[i] > maxim) ? h[i] : maxim;
        FORI(i,1,n) SD(k[i]);

        dp[0][0] = 0;
        FORI(j,1,2*maxim) dp[0][j] = inf;

        FORI(i,1,n)
        {
            FORI(j,0,2*maxim)
            {
                dp[i][j] = dp[i-1][j];
                if(k[i] <= j)
                    dp[i][j] = min(dp[i][j] , 1 + dp[i][ j-k[i] ] );
            }
        }
        res = 0;
        FORI(i,1,n)
            res = res + dp[n][ 2*h[i] ];
        printf("%d\n",res);
    }

    return 0;
}
