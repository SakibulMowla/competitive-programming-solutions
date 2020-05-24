#include "stdio.h"
#include "math.h"
#include "stdlib.h"

#define SZ 1000010

const int mod = 1000000007;

int dp[SZ];

int main()
{
    int i,j,k,n,g,t;

    dp[0] = dp[1] = 1;

    for(i=2; i<SZ; i++)
        dp[i] = (dp[i-1] + dp[i-2]) % mod;

    while(scanf("%d",&t) == 1)
    {
        while(t--)
        {
            scanf("%d %d",&n,&g);
            j = dp[n];
            k = 0;
            while(j)
            {
                if(j % 2) k++;
                j /= 2;
            }
            if(k == g) printf("CORRECT\n");
            else printf("INCORRECT\n");
        }
    }

    return 0;
}
