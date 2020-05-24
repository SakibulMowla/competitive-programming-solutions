#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;

ll x[] = {0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000LL};
ll y[] = {0, 9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999, 9999999999LL};


int main()
{
    ll t, l, r, i, a, b, ans;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&l,&r);

        ans = 0LL;

        for(i=1; i<=10; i++)
        {
            if(l>=x[i] && l<= y[i])
            {
                b = min(y[i], r);
                b = (b * (b+1)) / 2;
                a = (l * (l-1)) / 2;
                b = (b - a) % mod;
                b = (b * i) % mod;
                ans = b;
                i++;
                break;
            }
        }

        for(; i<=10; i++)
        {
            if(r >= x[i])
            {
                b = min(y[i], r);
                b = (b * (b+1)) / 2;
                a = (x[i] * (x[i]-1)) / 2;
                b = (b - a) % mod;
                b = (b * i) % mod;
                ans = (ans + b) % mod;
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}
