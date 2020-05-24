#include <bits/stdc++.h>

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))

typedef long long ll;
typedef pair<ll,ll> pii;

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

vector <ll> num;
ll csum[SZ];

int main()
{
    ll n, i, j, k, l;

    scanf("%lld",&n);

    num.push_back(0);

    for(i=0; i<n; i++)
    {
        scanf("%lld",&j);
        if(j < 0)
            num.push_back(-j);
    }

    scanf("%lld",&k);

    sort(num.begin(), num.end());

    l = sz(num)-1;

    for(i=1;i<=l;i++)
        csum[i] += num[i] + csum[i-1];

    ll ans = 1e16, tmp;

    for(i=l;i>=0;i--)
    {
        tmp = k * num[i];

        if(i != l)
        {
            tmp += (csum[l] - csum[i]) - num[i]*(l-i);
        }

        ans = min(ans, tmp);
    }

    printf("%lld\n",ans);

    return 0;
}
