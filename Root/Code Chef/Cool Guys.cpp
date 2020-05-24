#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int main()
{
    ll t, n, i, res, root, den, g;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        root = sqrt(n);
        res = 0;

        for(i=1;i<=root;i++)
        {
            res = res + (n / i);
        }

        res = 2 * res - root * root;
        den = n * n;

        g = gcd(res, den);

        res /= g;
        den /= g;

        printf("%lld/%lld\n",res, den);
    }

    return 0;
}
