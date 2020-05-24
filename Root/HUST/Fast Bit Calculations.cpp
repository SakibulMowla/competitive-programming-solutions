#include "stdio.h"
#include "string.h"
#define SZ 35

typedef long long ll;
ll N , dp[SZ][2][2];
ll arr[SZ];

ll solve(ll indx,ll flag,ll last)
{
    if(indx == N) return 0ll;
    ll &ret = dp[indx][flag][last];
    if(ret != -1) return ret;

    ll start = 0ll, end = 1ll;

    if(flag) end = arr[indx];

    ret = 0ll;
    if(start != end) ret += solve(indx+1,0,start);
//    else ret += solve(indx+1,flag,start);
    if(end == 1)
    {
        ret += solve(indx+1,flag,end);
        if(last == 1) ret++;
    }
    else ret += solve(indx+1,flag,end);
    printf("indx = %lld end = %lld last = %lld flag = %lld ",indx,end,last,flag);
    printf("ret = %lld\n",ret);
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
        for(i=0; i<N; i++) printf("%lld",arr[i]);
        printf("\n");
        memset(dp,-1,sizeof(dp));
        printf("Case %lld: %lld\n",++t,solve(0ll,1ll,0ll));
    }

    return 0;
}
