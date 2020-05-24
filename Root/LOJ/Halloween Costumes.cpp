#include "bits/stdc++.h"
using namespace std;

const int inf = 1<<28;
#define SZ 105

int dp[SZ][SZ];
int arr[SZ];

int solve(int left, int riht)
{
    int &ret = dp[left][riht];

    if(ret != -1)   return ret;
    if(left > riht) return ret = 0;

    int i;
    ret = inf;

    for(i=riht-1; i>=left; i--)
        if(arr[i] == arr[riht])
            ret = min(ret, solve(left, i) + solve(i+1, riht-1));

    ret = min(ret, 1 + solve(left, riht-1));

    return ret;
}

int main()
{
    int test=0, t, i, j, n;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        for(i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
            for(j=1; j<=n; j++)
                dp[i][j] = -1;
        }

        printf("Case %d: %d\n",++test,solve(1, n));
    }

    return 0;
}
