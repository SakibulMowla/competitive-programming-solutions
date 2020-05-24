#include "stdio.h"
#include "string.h"
#define SZ 35

typedef long long ll;
ll N , dp[SZ][3][3] , dp1[SZ][3][3];
ll arr[SZ];

ll solve1(ll indx,ll flag,ll last)
{
    if(indx == N) return 1ll;
    ll &ret1 = dp1[indx][flag][last];
    if(ret1 != -1) return ret1;
    ret1 = 0ll;
    if(flag && arr[indx] == 0)
    {
        ret1 += solve1(indx+1,flag,0);
    }
    else
    {
        ret1 += solve1(indx+1,0,0);
        ret1 += solve1(indx+1,flag,1);
    }

    return ret1;
}


ll solve(ll indx,ll flag,ll last)
{
    if(indx == N) return 0ll;
    ll &ret = dp[indx][flag][last];
    if(ret != -1) return ret;
    ret = 0ll;
    if(flag && arr[indx] == 0)
    {
        ret += solve(indx+1,flag,0);
    }
    else
    {
        if(last == 1)
        {
//            ret++;
            ret += solve1(indx+1,flag,1);
        }
        ret += solve(indx+1,0,0);
        ret += solve(indx+1,flag,1);
    }

    return ret;
}

int main()
{
    ll t=0,test,n,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        i = 0;
        do
        {
            arr[i++] = n % 2;
            n /= 2;
        }
        while(n);
        N = i ;
        for(j=0; j<N/2; j++)
            n = arr[j] , arr[j] = arr[N-j-1] , arr[N-j-1] = n;
//        for(i=0; i<N; i++) printf("%lld",arr[i]);
//        printf("\n");
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        printf("Case %lld: %lld\n",++t,solve(0ll,1ll,0ll));
    }

    return 0;
}
