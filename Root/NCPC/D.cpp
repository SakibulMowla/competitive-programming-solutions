#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100000010

bool arr[SZ];
vector <ll> prime;

void sieve () {
    int lim = sqrt(1E8);
    for (int i = 3; i <= lim; i++) {
        if (!arr[i]) {
            for (int j = i * i; j < SZ; j += i + i) {
                arr[j] = 1;
            }
        }
    }
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2) {
        if (!arr[i]) {
            prime.pb(i);
        }
    }
//    for (int i = 0; i < 25; i++) {
//        printf("%d\n", prime[i]);
//    }
//    cout << endl;
    return;
}

ll gcd (ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

pll factor (ll n) {
    ll g = 0;
    ll nod = 1;
    for (int i = 0; i < sz(prime) && prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            ll pw = 0;
            while (n % prime[i] == 0) {
                pw++;
                n /= prime[i];
            }
            nod *= (pw + 1LL);
            g = gcd(g, pw);
        }
    }
    if (n != 1) g = gcd(g, 1), nod *= 2LL;
    return {g, nod};
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    sieve();

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        pll u = factor(a);
        pll v = factor(b * u.X);

        ll ans = v.Y - 1;

//        v = factor(u.X);
//        ans += v.Y - 1;

        printf("Case %d: %lld\n", i + 1, ans);
    }

    return 0;
}




