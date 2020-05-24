#include "stdio.h"
#include "string.h"
#define SZ 20

template <class T> T max(T a,T b) { return a > b ? a : b; }
typedef long long ll;
ll n , matrix[SZ][SZ] ,dp[SZ][(1<<16)+2];

ll Set(ll n,ll pos) { return n = n | (1<<pos); }
ll reset(ll n,ll pos) { return n = n & ~(1<<pos); }
ll check(ll n,ll pos) { return n & (1<<pos); }

ll solve(ll indx,ll mask)
{
    if(indx == n) return 0;
    ll i,&ret=dp[indx][mask],tmp;
    if(ret != -1) return ret;
    ret = 0ll;
    for(i=0; i<n; i++)
    {
        if(!check(mask,i))
        {
            tmp = mask;
            tmp = Set(tmp,i);
            ret = max(ret , solve(indx+1,tmp) + matrix[indx][i]);
        }
    }
    return ret;
}

int main()
{
    ll t=0,test,i,j,k;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        k = (1<<n) + 2;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++) scanf("%lld",&matrix[i][j]);
            for(j=0;j<k;j++) dp[i][j] = -1;
        }
        printf("Case %lld: %lld\n",++t,solve(0,0));
    }

    return 0;
}
