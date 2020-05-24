#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    ll k;
    cin >> n >> k;

    ll g = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        g = __gcd(g, x);
    }


//    cout << ">> " << g << endl;
    ll ans = 0;

    for (ll i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            ll p = i;
            if (p > 1) {
                ans = max(ans, (k / p) * p);
            }
            p = g / i;
            if (p > 1) {
                ans = max(ans, (k / p) * p);
            }
        }
    }

    cout << ans << endl;

    return 0;
}



