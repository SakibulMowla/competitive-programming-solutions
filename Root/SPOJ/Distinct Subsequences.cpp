#include "stdio.h"
#include "string.h"

#define MAX 100010
typedef long long ll;

const ll mod = 1000000007LL;

char arr[MAX];
ll dp[MAX];
ll last[30];

int main()
{
    ll t, i , l;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%s",arr);
        l = strlen(arr);

        memset(last,-1,sizeof(last));
        dp[0] = 1;

        for(i=0;i<l;i++)
        {
            dp[i+1] = 2 * dp[i];

            if(dp[i+1] >= mod) dp[i+1] -= mod;

            if(last[ arr[i] - 'A' ] != -1)
            {
                dp[i+1] -= dp[ last[ arr[i] - 'A' ] ];
                if(dp[i+1] < 0 ) dp[i+1] += mod;
            }

            last[ arr[i] - 'A' ] = i;
        }

        printf("%lld\n", dp[l]);
    }

    return 0;
}
