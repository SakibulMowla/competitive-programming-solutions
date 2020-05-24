#include "stdio.h"
typedef long long ll;

ll n , k , dp[70][70][110];

ll solve(ll pos,ll ones,ll mod)
{
    if(pos == n)
    {
        if(mod == 0 && ones == n / 2) return 1ll;
        return 0ll;
    }
    if(dp[pos][ones][mod] != -1) return dp[pos][ones][mod];
    ll &ret = dp[pos][ones][mod];
    ret = 0ll;
    ret += solve(pos+1,ones+1,(2*mod+1)%k);
    if(pos) ret += solve(pos+1,ones,(2*mod)%k);
    return ret;
}

int main()
{
    ll t=0,test,i,j,l;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld %lld",&n,&k);
        for(i=0;i<=n;i++) for(j=0;j<=n;j++) for(l=0;l<=k;l++) dp[i][j][l] = -1;
        printf("Case %lld: ",++t);
        cnt = 0;
        if(n%2 || !k) printf("0\n");
        else printf("%lld\n",solve(0,0,0));
    }

    return 0;
}
