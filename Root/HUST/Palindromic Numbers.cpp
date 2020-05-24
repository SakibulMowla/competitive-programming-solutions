#include "stdio.h"
#include "string.h"
#define SZ 20

typedef long long ll;
ll n , dp[SZ][3][SZ] , palin[SZ];
char arr[SZ];

ll solve(ll indx,ll flag,ll len)
{
    if(indx == n) return 1ll;
    ll &ret = dp[indx][flag][len];
    if(ret != -1) return ret;

    ll i,start=0ll,end=9ll;
    if(flag) end = (ll)arr[indx] - '0';

    ret = 0ll;
    for(i=start; i<end; i++)
    {
        if(i == 0ll && len == 0ll)
            ret += solve(indx+1,0ll,len);
        else if(len == 0)
            palin[indx] = i , ret += solve(indx+1,0ll,len+1);
        else if(palin[indx-len] == i)
            palin[indx] = i , ret += solve(indx+1,0ll,len+1);
    }
    if(i == 0ll && len == 0ll)
        ret += solve(indx+1,flag,len);
    else if(len == 0)
        palin[indx] = i , ret += solve(indx+1,flag,len+1);
    else if(palin[indx-len] == i)
        palin[indx] = i , ret += solve(indx+1,flag,len+1);

    return ret;
}

int main()
{
    ll t=0,test,i,j,k;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%s",arr);
        n = strlen(arr);
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve(0ll,1ll,0ll));
    }

    return 0;
}
