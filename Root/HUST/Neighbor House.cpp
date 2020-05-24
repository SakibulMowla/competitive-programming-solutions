#include "bits/stdc++.h"
using namespace std;

#define SZ 22

int cost[SZ][3];
int n;
int dp[SZ][SZ];

int solve(int prev, int indx)
{
    if(indx == n)
        return 0LL;

    int &ret = dp[prev][indx];
    if(ret != -1)
        return ret;

    int i;
    ret = 1<<28;

    for(i=0;i<3;i++)
        if(i != prev)
            ret = min(ret, cost[indx][i] + solve(i, indx+1));

    return ret;
}

int main()
{
    int test=0, t, i, j, k;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<3;j++)
                scanf("%d",&cost[i][j]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                dp[i][j] = -1;

        k = 1<<28;

        for(i=0;i<3;i++)
            k = min(k, cost[0][i] + solve(i, 1));

        printf("Case %d: %d\n",++test,k);
    }

    return 0;
}
