#include "stdio.h"
#include "iostream"

using namespace std;

#define SZ 20

typedef long long ll;

bool mat[SZ+2][SZ+2];
ll dp[(1<<SZ)+2];
int n;


int main()
{
    int t, i, j, k, indx;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&mat[i][j]);

        k = 1<<n;

        for(i=0; i<=k; i++)
            dp[i] = 0;

        dp[0] = 1LL;

        for(i=0; i<k; i++)
        {
            indx = __builtin_popcount(i);
            for(j=0; j<n; j++)
            {
                if((i&(1LL<<j)) == 0 && mat[indx][j] == 1)
                    dp[i|(1LL<<j)] += dp[i];
            }
        }

        printf("%lld\n",dp[k-1]);
    }

    return 0;
}
