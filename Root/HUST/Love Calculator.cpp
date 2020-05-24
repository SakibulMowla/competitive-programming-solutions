#include "stdio.h"
#include "string.h"
#define SZ 35

typedef long long ll;
char arr1[SZ] , arr2[SZ];
ll dp[SZ][SZ] , dp1[SZ][SZ] , len1 , len2;
template <class T> T min(T a,T b) { return a < b ? a : b; }

ll length(ll n,ll m)
{
    ll &ret = dp[n][m];
    if(n == len1) return ret = len2-m;
    else if(m == len2) return ret = len1-n;

    if(ret != -1) return ret;
    if(arr1[n] == arr2[m]) ret = 1 + length(n+1,m+1);
    else ret = min(length(n+1,m) , length(n,m+1)) + 1;
    return ret;
}


ll variety(ll n,ll m)
{
    if(n == len1 || m == len2) return 1ll;
    ll &ret = dp1[n][m] ;
    if(ret != -1) return ret;
    if(arr1[n] == arr2[m]) return ret = variety(n+1,m+1);
    ll i,j;
    i = length(n+1,m);
    j = length(n,m+1);
    if(i == j) return ret = variety(n+1,m) + variety(n,m+1);
    else if(i < j) return ret = variety(n+1,m);
    else return ret = variety(n,m+1);
}

int main()
{
    ll t=0,test,i,j;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%s %s",arr1,arr2);
        len1 = strlen(arr1);
        len2 = strlen(arr2);
        for(i=0;i<=len1;i++) for(j=0;j<=len2;j++) dp[i][j] = -1 , dp1[i][j] = -1;
        printf("Case %lld: %lld %lld\n",++t,length(0,0),variety(0,0));
    }

    return 0;
}
