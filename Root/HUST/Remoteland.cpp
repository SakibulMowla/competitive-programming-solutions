#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1000000007LL;

ll BigMod (ll B,ll P,ll M) {
    ll R = 1LL % M;
    while(P) {
        if(P & 1LL) {
            R = (R * B) % M;
        }
        P >>= 1LL;
        B = (B * B) % M;
    }
    return R;
}

#define SZ  10000000+10

bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(10000000);
    for (int i = 3; i <= k; i += 2)
        if (!arr[i])
            for (ll j = (ll)i * (ll)i; j < SZ; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime.pb(i);
}

ll fact[SZ];

void pre () {
    fact[0] = 1;
    for (int i = 1; i <= 10000000; i++) {
        fact[i] = (i * fact[i-1]) % mod;
    }
}

int howManyTimes (int n, int prm) {
    int cnt = 0;
    while (n >= prm) {
        cnt += n / prm;
        n /= prm;
    }
    return cnt;
}

int main() {
    sieve();
    pre();

    int n;
    while (scanf("%d", &n) == 1 && n) {
        ll ans = 1LL;

        for (int i = 0; i < sz(prime) && prime[i] <= n; i++)
            if (howManyTimes(n, prime[i]) & 1)
                ans = (ans * prime[i]) % mod;

        ans = (fact[n] * BigMod(ans, mod-2, mod)) % mod;

        cout << ans << '\n';
    }

    return 0;
}




