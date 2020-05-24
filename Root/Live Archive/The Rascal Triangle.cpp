#include <bits/stdc++.h>

using namespace  std;

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
const ll mod = 1LL;

#define SZ  110

ll even (ll n) {
    return n * (n + 1LL);
}

ll odd (ll n) {
    return n * n;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int tt;
        ll n, r;
        cin >> tt >> n >> r;

        cout << tt << ' ';
        if (r > n) {
            cout << 0;
        } else if (r == 0 || n == r) {
            cout << 1;
        } else {
            if (r > n/2LL) {
                r = n - r;
            }
            ll ans;
            if (n&1) {
                ans = even(n/2LL) - even(n/2-r);
            } else {
                ans = odd(n/2) - odd(n/2-r);
            }
            ans++;
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}


