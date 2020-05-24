// O( 2 * max(h[i]) )

#include "stdio.h"

#define inf 1<<28
#define min(a,b) a < b ? a : b
#define SZ 1010
#define SD(a) scanf("%d",&a)
#define FOR(i,n) for(i=0;i<n;i++)
#define FORI(i,a,n) for(i=a;i<=n;i++)

int dp[SZ] , h[SZ/2] , k[SZ/2];

int main()
{
    int n,i,j,t,maxim,res;
    SD(t);
    while(t--)
    {
        maxim = -1;
        SD(n);
        FORI(i,1,n) SD(h[i]) , maxim = (h[i] > maxim ) ? h[i] : maxim ;
        FORI(i,1,n) SD(k[i]);

        dp[0] = 0;
        FORI(i,1,2*maxim) dp[i] = inf;

        FORI(i,1,n)
        {
            FORI(j,k[i],2*maxim)
            {
                dp[j] = min(dp[j] , 1 + dp[ j-k[i] ]);
            }
        }
        res = 0;
        FORI(i,1,n)
            res = res + dp[2*h[i]];
        printf("%d\n",res);
    }

    return 0;
}
