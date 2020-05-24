#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1E9+7;

#define SZ  100010

ll BigMod (ll b, ll p, ll m) {
    ll r = 1LL%m;
    while (p) {
        if (p & 1) r = (r * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return r;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll k, n;
        cin >> k >> n;
        if (n == 1) {
            cout << 1 << endl;
        } else if (n <= 3) {
            cout << k % mod << endl;
        } else {
            cout << BigMod(k, BigMod(2LL, n - 3, mod - 1), mod) << endl;
        }
    }

    return 0;
}




