#include <bits/stdc++.h>

using namespace  std;

#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;


int main()
{
    ll n, i, j;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&j);

    printf("%lld\n",n);

    while(n)
    {
        printf("%lld %lld\n",n,n);
        n--;
    }

    return 0;
}

