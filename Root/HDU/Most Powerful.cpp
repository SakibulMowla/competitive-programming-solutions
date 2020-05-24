#include "bits/stdc++.h"
using namespace std;

#define SZ 1030

int dp[SZ], arr[12][12], n;

int solve(int mask)
{
    int &ret = dp[mask];
    if(ret != -1) return ret;

    ret = 0;
    int i, j;

    for(i=0; i<n; i++) if(mask&(1<<i))
            for(j=0; j<n; j++) if(i!=j && mask&(1<<j))
                    ret = max(ret, arr[i][j] + solve(mask&~(1<<j)));

    return ret;
}

int main()
{
    int i, j, lim;

    while(scanf("%d",&n) == 1 && n)
    {
        lim = 1<<n;
        --lim;
        for(i=0; i<=lim; i++)
            dp[i] = -1;
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%d",&arr[i][j]);
        printf("%d\n",solve(lim));
    }

    return 0;
}
