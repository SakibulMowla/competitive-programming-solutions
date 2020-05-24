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
const ll mod = 1000000007;

#define SZ  100010

ll xorUpToK(ll k) {
    if (k < 0) return 0LL;
    ll rem = k % 4LL;
	switch (rem) {
		case 0: return k;
		case 1: return 1LL;
		case 2: return k + 1LL;
		case 3: return 0LL;
	}
}

ll RangeXor (ll a, ll b) {
    if (a > b) return 0;
//    cout << (xorUpToK(b) ^ xorUpToK(a - 1LL)) << endl;
    return xorUpToK(b) ^ xorUpToK(a - 1LL);
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll x, m;
        cin >> x >> m;

        if (m == 0) {
//            if (x) cout << "ALICE" << endl;
            cout << "BOB" << endl;
        } else {
            ll ans = 2LL * RangeXor(x / 2LL, (x / 2LL) + m - 1LL);
            if ((x & 1) && (m & 1)) ans++;

            if (ans) cout << "ALICE" << endl;
            else cout << "BOB" << endl;
        }
    }

    return 0;
}


