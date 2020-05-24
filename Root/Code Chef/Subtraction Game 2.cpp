#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>

using namespace  std;

typedef long long ll;

template <class T> T gcd(T a, T b)
{
    while(b == 0) return a;
    return gcd(b,a%b);
}

ll power(ll b,ll p)
{
    if(p == 0) return 1LL;
    ll x = power(b,p/2);
    x *= x;
    if(p%2) x *= b;
    return x;
}

#define SZ 100
ll n , arr[SZ] , dp[SZ][10100];

ll solve(ll indx,ll g)
{
    if(indx == n)
    {
        if(g == 1LL) return 1LL;
        return 0LL;
    }

    ll &ret = dp[indx][g];
    if(ret != -1) return ret;
    if(g == 1) return ret = power(2LL,n-indx);

    return ret = solve(indx+1,g) + solve(indx+1 , gcd(g,arr[indx]));
}


int main()
{
    ll t,m,i,j,ans;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        m = ans = 0;

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]) , m = arr[i] > m ? arr[i] : m;

        for(i=0;i<n;i++)
            for(j=0;j<=m;j++)
                dp[i][j] = -1;

        for(i=0;i<n;i++)
            ans += solve(i+1,arr[i]);

        printf("%lld\n",ans);
    }

    return 0;
}
