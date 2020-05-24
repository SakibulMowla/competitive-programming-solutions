using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define MAX (1LL<<20)+2
#define MAX1 22

typedef long long ll;

ll dp[MAX];
ll arr[MAX1][MAX1];

int main()
{
//    freopen("1.txt","r",stdin);
    ll t, n, i, j, k, mask;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%lld",&arr[i][j]);

        k = (1LL<<n) - 1LL; // initializing mask;
        memset(dp,0,sizeof(ll)*(k+2));

        dp[0] = 1;

        for(mask=0; mask<k; mask++)
        {
            j = __builtin_popcount(mask);
            for(i=0; i<n; i++)
            {
                if(arr[j][i] == 1 && (mask & (1<<i)) == 0 )
                    dp[mask | (1<<i)] += dp[mask] ;
            }
        }

        printf("%lld\n", dp[k]);
    }

    return 0;
}
