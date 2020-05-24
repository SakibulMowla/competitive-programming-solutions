#include "stdio.h"
#define SZ 22

typedef long long ll;

ll nCr[SZ][SZ] , sub[SZ] , fac[SZ] ;

void permutation(ll n)
{
    ll i;
    fac[0] = 1;
    for(i=1; i<=n; i++)
        fac[i] = i * fac[i-1];
}

void combination(ll n)
{
    ll i,j;

    for(i=0; i<=n; i++)

        for(j=0; j<=i; j++)
        {
            if(i == j) nCr[i][j] = 1LL;
            else if(j == 1) nCr[i][j] = i;
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
        }

}

void subfactorial(ll n)
{
    ll i,j,ans;

    for(i=0; i<=n; i++)
    {
        ans = fac[i];

        for(j=1;j<=i;j++)
        {
            if(j%2) ans -= ( fac[i] / fac[j] );
            else ans += ( fac[i] / fac[j]);
        }

        sub[i] = ans;
    }

}

int main()
{

    permutation(20LL);
    combination(20LL);
    subfactorial(20LL);

    ll n,m,i,j,ans;

    while(scanf("%lld %lld",&n,&m) == 2)
    {

        ans = 0LL;

        for(i=0;i<=m;i++)
        {
            ans += ( nCr[n][i] * sub[n-i] );
        }

        printf("%lld\n",ans);
    }

    return 0;
}
