#include "bits/stdc++.h"

using namespace std;

#define SZ 1010

typedef long long ll;

long long arr[SZ];
long long dp[SZ][SZ];

long long fastMax(long long x, long long y) {return (((y-x)>>(32-1))&(x^y))^y;}

inline void read (long long &n)
{
    n = 0;
    long long  i = getchar_unlocked();

    while (i < '0' || i > '9')
        i = getchar_unlocked();

    while (i >= '0' && i <= '9')
    {
        n = (n << 3) + (n << 1) + i - '0';
        i = getchar_unlocked();
    }
}

long long  main()
{
    long long n, m, i, j;

    while(1)
    {
        read(n);
        read(m);
        if(n == 0 && m == 0) break;
        for(i=1; i<=n; i++)
        {
            read(arr[i]);
            memset(dp[i], 0, sizeof(ll)*(n+2));
            dp[i][1] = ( dp[i-1][1] + arr[i] ) % m;
        }
        for(i=1; i<=n; i++)
        {
            for(j=2; j<=i; j++)
            {
                dp[i][j] = ( ( dp[i-1][j-1] * arr[i] ) % m + dp[i-1][j] ) % m;
            }
        }
        j = 0ll;
        for(i=1;i<=n;i++)
            j = fastMax(j, dp[n][i]);
        prlong long f("%lld\n",j);
    }

    return 0;
}
