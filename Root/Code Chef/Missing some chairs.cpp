#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


ll BigMod(ll B,ll P,ll M)
{
    ll R=1%M;
    while(P>0)
    {
        if(P%2==1)
        {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

const ll mod = 1e9+7;

int main()
{

    ll t, n;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        n = ( BigMod(2LL, n, mod) - 1 + mod ) % mod;
        printf("%lld\n",n);
    }


    return 0;
}



