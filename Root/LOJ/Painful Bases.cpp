#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
ll dp[(1<<16)+2][22];

char arr[18];
int base, k, n;

ll solve(int mask, int mod)
{
    ll &ret = dp[mask][mod];

    if(ret != -1) return ret;
    if(!mask) return ret = !mod;

    int i;
    ret = 0;

    for(i=0; i<n; i++)
        if(mask & (1<<i))
            ret += solve(mask&~(1<<i), ( (mod*base)+arr[i] ) % k );

    return ret;
}

int main()
{
    int test=0, t, i, j, lim;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&base,&k);
        scanf(" %s",arr);

        n = strlen(arr);

        for(i=0; arr[i]; i++)
            arr[i] < 'A' ? arr[i] -= '0' : arr[i] = arr[i] - 'A' + 10;

        lim = 1<<n;

        for(i=0; i<lim; i++)
            for(j=0; j<=20; j++)
                dp[i][j] = -1;

        printf("Case %d: %lld\n",++test, solve(lim-1, 0));
    }

    return 0;
}
