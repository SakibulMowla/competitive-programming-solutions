using namespace std;

#include "stdio.h"
#include "string.h"
#include "iostream"

#define MAX (1LL<<20)+2
#define MAX1 22

typedef long long ll;

ll Set(ll pos,ll mask)
{
    return mask | (1LL<<pos);
}
ll reset(ll pos,ll mask)
{
    return mask & ~(1LL<<pos);
}
bool check(ll pos,ll mask)
{
    return mask & (1LL<<pos);
}

ll dp[MAX] , n;
ll arr[MAX1][MAX1];

ll solve(ll indx,ll mask)
{
    ll &ret = dp[mask];

    if(ret != -1) return ret;
    if( !mask ) return 1LL;

    ll i, tmp;
    ret = 0LL;
    for(i=0; i<n; i++)
    {
        if(arr[indx][i] == 1LL && check(i,mask))
        {
            tmp = reset(i,mask);
            ret += solve(indx+1 , tmp);
        }
    }

    return ret;
}

int main()
{
//    freopen("1.txt","r",stdin);
    ll t, i, j, k;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                scanf("%lld",&arr[i][j]);

        k = (1LL<<n) - 1LL; // initializing mask;

        for(j=0; j<=k; j++)
            dp[j] = -1;

        printf("%lld\n", solve(0,k));
    }

    return 0;
}
