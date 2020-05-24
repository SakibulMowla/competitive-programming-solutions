#include "stdio.h"
#define SZ 1010

typedef long long ll;
ll mod = 1000000007ll;

ll fact[SZ] , nCr[SZ][SZ];

int main()
{
    ll t=0ll,test,i,j,k,n,m,ans,inex,space;

    for(i=0; i<SZ; i++)
    {
        if(i==0ll or i==1ll) fact[i] = 1ll;
        else fact[i] = (i * fact[i-1ll]) % mod;
        for(j=0ll; j<=i; j++)
        {
            if(i == 0ll or j == 0ll or i==j) nCr[i][j] = 1ll;
            else if(j == 1ll) nCr[i][j] = i;
            else nCr[i][j] = (nCr[i-1ll][j] + nCr[i-1ll][j-1ll]) % mod;
        }
    }

    scanf("%lld",&test);

    while(test--)
    {
        scanf("%lld %lld %lld",&n,&m,&k);
        ans = nCr[m][k];
        inex = 0ll;
        space = m - k;
        for(i=0,j=n-k; i<=m-k; i++,j--)
        {
            if(i%2==0) inex = (inex + nCr[space][i] * fact[j]) % mod;
            else inex = (inex - nCr[space][i] * fact[j]) % mod;
        }
        if(inex < 0) inex += mod;
        ans = (ans * inex) % mod;
        printf("Case %lld: %lld\n",++t,ans);
    }

    return 0;
}
