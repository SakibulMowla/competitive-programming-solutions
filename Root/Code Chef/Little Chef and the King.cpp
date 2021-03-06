#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

ll _power (ll b, ll p) {
    ll ans = 1LL;
    for (int i = 0; i < p; i++) {
        ans *= b;
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n, k;
        cin >> n >> k;

        if (k == 1) {
            cout << n << '\n';
            continue;
        }

        ll pre = -1;
        ll mul = 1LL;
        ll pwr;
        for (ll p = 0; ; p++) {
            if (mul < pre || mul > n) {
                break;
            }
            pwr = p;
            mul *= k;
        }

        int cnt = 0;
        for (ll p = pwr; p >= 0; p--) {
            ll now = _power(k, p);

            ll ans = 0;
            ll lo = 0;
            ll hi = k;
            while (lo <= hi) {
                ll mid = (lo + hi) >> 1LL;
                if (n - mid * now >= 0) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            n -= now * ans;
            cnt += ans;
        }

        assert(n == 0);
        cout << cnt << '\n';
    }


    return 0;
}



