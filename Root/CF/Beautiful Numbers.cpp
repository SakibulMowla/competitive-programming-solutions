using namespace std;

#include "stdio.h"
#include "iostream"
#define MAX 1000100

typedef long long ll;
const ll mod = 1000000007LL;

ll bigmod(ll b,ll p,ll m)
{
    if(p == 0) return 1LL%m;
    ll x = bigmod(b, p/2, m);
    x = (x*x) % m;
    if(p%2 == 1) x = (b*x) % m;
    return x;
}

ll chk(ll a,ll b,ll n)
{
    while(n)
    {
        if(!(n%10==a || n%10==b)) return 0;
        n /= 10;
    }
    return 1;
}

ll fac[MAX];

void pre(ll n)
{
    ll i;
    fac[0] = 1;
    for(i=1;i<=n;i++)
        fac[i] = ( i * fac[i-1] ) % mod;
}

int main()
{
    ll n,a,b,i,sum,ans,tmp;

    while(cin >> a >> b >> n)
    {
        pre(n);
        ans = 0;

        for(i=0;i<=n;i++)
        {
            sum = a*i + b*(n-i);
            if(chk(a,b,sum))
            {
                tmp = fac[n];
                tmp = (tmp * bigmod(fac[i], mod-2, mod)) % mod;
                tmp = (tmp * bigmod(fac[n-i], mod-2, mod)) % mod;
                ans = (ans + tmp) % mod;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
