#include "bits/stdc++.h"
using namespace std;

#define SZ 3010
const int inf = 1e9;

int a[SZ], b[SZ], c[SZ];
int dp[SZ][2];
int n;

int solve(int indx, int flag)
{
    if(indx == n) return 0;

    int &ret = dp[indx][flag];
    if(ret != -1) return ret;

    if(flag)
    {
        ret = solve(indx+1, 1) + b[indx];
        if(indx < n-1) ret = max(ret, solve(indx+1, 0) + c[indx]);
    }
    else
    {
        ret = solve(indx+1, 1) + a[indx];
        if(indx < n-1) ret = max(ret, solve(indx+1, 0) + b[indx]);
    }

    return ret;
}


int main()
{
    int i;

    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        for(i=0;i<n;i++)
            scanf("%d",&c[i]);

        for(i=0;i<=n;i++)
            dp[i][0] = dp[i][1] = -1;

        printf("%d\n",solve(0, 0));
    }

    return 0;
}
