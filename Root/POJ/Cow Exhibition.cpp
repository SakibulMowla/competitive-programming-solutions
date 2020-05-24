#include "stdio.h"
#include "string.h"

#define SZ 110

struct data
{
    int smrt, funn, smrt1, funn1;
};

data dp[SZ];
int smart[SZ], funny[SZ];

int main()
{
    int i, j, k, n;
    int tmps, tmpf, tmps1, tmpf1;

    scanf("%d",&n);

    for(i=1; i<=n; i++)
        scanf("%d %d",&smart[i],&funny[i]);

    dp[0].funn = dp[0].smrt = 0;

    for(i=1; i<=n; i++)
    {
        tmps = dp[i-1].smrt + smart[i];
        tmpf = dp[i-1].funn + funny[i];
        tmps1 = dp[i-1].smrt1 + smart[i];
        tmpf1 = dp[i-1].funn1 + funny[i];

        if((tmps >= 0 && tmpf >= 0) && (tmps1 >= 0 && tmpf1 >= 0))
        {
            if(tmps + tmpf > tmps1 + tmpf1)
                dp[i].smrt = tmps, dp[i].funn = tmpf;
            else
                dp[i].smrt = tmps1, dp[i].funn = tmpf1;
        }

        else if((tmps >= 0 && tmpf >= 0))
            dp[i].smrt = tmps, dp[i].funn = tmpf;

        else if((tmps1 >= 0 && tmpf1 >= 0))
            dp[i].smrt = tmps1, dp[i].funn = tmpf1;

        else
            dp[i].smrt = dp[i].funn = 0;


    }


    return 0;
}
