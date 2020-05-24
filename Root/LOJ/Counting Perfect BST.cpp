#include <bits/stdc++.h>
using namespace  std;

#define sz(x) (int)x.size()
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;

#define SZ 1010
const ll mod = 100000007LL;

vector <ll> perfect;

void generate()
{
    ll i, j;

    for(i=2; i<=100000LL; i++)
        for(j=i*i; j<=10000000000LL; j*=i)
            perfect.push_back(j);

    sort(perfect.begin(), perfect.end());
    Unique(perfect);
}

ll dp[2010];

ll solve(ll n)
{
    ll &ret = dp[n];

    if(ret != -1) return ret;
    if(n <= 1) return ret = 1;

    ll i, ret1, ret2;
    ret = 0;

    for(i=0; i<n; i++)
    {
        ret1 = solve(i);
        ret2 = solve(n-i-1);

        ret = (ret + (ret1*ret2) % mod ) % mod;
    }

    return ret;
}

int main()
{
    generate();
    memset(dp, -1, sizeof(dp));

    ll test=0, t, n, a, b;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&a,&b);

        a = lower_bound(perfect.begin(), perfect.end(), a) - perfect.begin();
        b = upper_bound(perfect.begin(), perfect.end(), b) - perfect.begin();

        printf("Case %lld: %lld\n",++test, b-a ? solve(b-a) : 0);
    }

    return 0;
}
