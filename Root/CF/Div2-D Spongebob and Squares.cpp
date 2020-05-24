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
using pll = pair <long long, long long>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("3.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    ll x;
    while (cin >> x) {
        vector <pll> ans;

        for (ll n = 1; n <= min(2000000LL, x); n++) {
            ll m = 6LL * x;
            m = m + (n * n * n) - n;
            if (m % (3LL * n * (n + 1LL)) == 0) {
                m /= (3LL * n * (n + 1LL));
                if (m >= n) {
                    ans.pb({n, m});
                }
            }
        }

        set <pll> ms;

        for (auto it: ans) {
            ms.insert(it);
            ms.insert({it.second, it.first});
        }

        cout << sz(ms) << endl;
        for (auto it: ms) {
            cout << it.first << ' ' << it.second << endl;
        }
    }


    return 0;
}

