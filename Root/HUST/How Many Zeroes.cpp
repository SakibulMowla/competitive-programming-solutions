#include "stdio.h"
#include "string.h"
#define SZ 12

typedef long long ll;

ll n , dp1[SZ][3] , dp[SZ][3][SZ];
char arr[12];

ll solve1(ll indx,ll flag)
{
    if(indx == n) return 1ll;
    ll &ret = dp1[indx][flag];
    if(ret != -1) return ret;
    ll i , start = 0ll , end = 9ll;
    if(flag) end = (ll)(arr[indx] - '0');
    ret = 0ll;
    for(i=start; i<end; i++)
        ret += solve1(indx+1,0);
    ret += solve1(indx+1,flag);
    return ret;
}

ll solve(ll indx,ll flag,ll digits,ll situ)
{
//    printf("situ = %lld\n",situ);
    if(indx == n) return 0ll;
    ll &ret = dp[indx][flag][digits];
    if(ret != -1) return ret;
    ll i , start = 0ll , end = 9ll;
    if(flag) end = (ll) (arr[indx] - '0');
    ret  = 0;
//    printf("indx = %lld  digits = %lld end = %lld flag = %lld situ = %lld\n",indx,digits,end,flag,situ);
    for(i=start; i<end; i++)
    {
        if(situ && i == 0) ret += solve1(indx+1,0);
        if(situ == 0 && indx == n-1 && i == 0) ret += solve1(indx+1,0);
        if(situ || i != 0) ret += solve(indx+1,0,digits+1,(10*situ)+i);
        else ret += solve(indx+1,0,digits,(10*situ)+i);
    }
    if(end == 0ll)
    {
        ret += solve1(indx+1,flag);
        ret += solve(indx+1,flag,digits+1,(10*situ)+i);
    }
    else ret += solve(indx+1,flag,digits+1,(10*situ)+i);
    return ret;
}

int main()
{
    ll t=0,test,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %s",&i,arr);
        n = strlen(arr);
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
        j = solve(0ll,1ll,0ll,0ll);
        if(i)
        {
            i--;
            sprintf(arr,"%lld",i);
//            printf("arr = %s\n",arr);
            n = strlen(arr);
            memset(dp,-1,sizeof(dp));
            memset(dp1,-1,sizeof(dp1));
            j = j - solve(0ll,1ll,0ll,0ll);
        }
        printf("Case %lld: %lld\n",++t,j);
    }

    return 0;
}
