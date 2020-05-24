#include "stdio.h"
#define SZ 110

typedef long long ll;
template <class T> T min(T a,T b) { return a < b ? a : b; }
const ll inf = (1LL<<28);

ll arr[SZ] , smoke[SZ][SZ] , col[SZ][SZ];

ll solve(ll start,ll end)
{
    ll &ret = smoke[start][end];

    if(ret != -1)
        return ret;

    if(start+1 == end)
    {
        col[start][end] = (arr[start] + arr[end]) % 100;
        return ret = smoke[start][end] = arr[start] * arr[end];
    }

    else if(start == end)
    {
        col[start][end] = arr[start];
        return ret = smoke[start][end] = 0;
    }

    ll i;

    ret = inf;

    for(i=start ; i < end ; i++)
    {
        solve(start,i);
        solve(i+1,end);
        if(  col[start][i] * col[i+1][end]   +  ( smoke[start][i] + smoke[i+1][end] )  < ret)
        {
            ret = col[start][i]*col[i+1][end] + smoke[start][i] + smoke[i+1][end];
            col[start][end] = (col[start][i] + col[i+1][end]) % 100;
        }
    }

    return ret;
}

int main()
{
    ll n,i,j;

    while(scanf("%lld",&n) == 1)
    {
        for(i=0; i<n; i++)
        {
            scanf("%lld",&arr[i]);
            for(j=0; j<n; j++)
                smoke[i][j] = -1;
        }
        printf("%lld\n",solve(0,n-1));
    }

    return 0;
}
