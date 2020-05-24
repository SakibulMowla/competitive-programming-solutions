#include "stdio.h"
#include "string.h"
#include "iostream"

using namespace std;

#define SZ 25
typedef long long ll;
const ll inf = 1e10;

ll dp[SZ][SZ], n;

ll solve(ll i,ll j)
{
    ll &ret = dp[i][j];
    if(ret != -1) return ret;

    ll p, q, one, two;
    ret = one = two = 0;

    if(i < j)
    {
        for(p=i; p<j; p++)
            ret = max(ret, solve(i,p) + solve(p+1,j));
    }
    else
    {
        if(i == n)
            one = 0;
        else if(i < n)
        {
            for(p=i+1; p<=n; p++)
                one = max(one , solve(p,1)+solve(p,j));
        }
        if(j == 0)
            two = 0;
        else if(j > 0)
        {
            for(p=1; p<j; p++)
                two = max(two, solve(i,p)+solve(n,p));
        }
        ret = one + two;
    }
    return ret;
}

int main()
{
    ll i, j;
    while(scanf("%lld",&n) == 1)
    {
        for(i=0; i<=n; i++)
            for(j=0; j<=n; j++)
                dp[i][j] = -1;
        scanf("%lld",&dp[n][1]);
        printf("%lld\n",solve(1,n));
    }

    return 0;
}
