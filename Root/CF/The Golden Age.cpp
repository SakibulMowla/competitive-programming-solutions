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


#define SZ 100010



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    ll x, y, l, r;
    cin >> x >> y >> l >> r;

    vector <ll> one, two;
    one.pb(1);
    ll last = 1;
    while (last <= r / x) {
        last = last * x;
        one.pb(last);
    }
    two.pb(1);
    last = 1;
    while (last <= r / y) {
        last = last * y;
        two.pb(last);
    }

    set <ll> ms;
    ms.insert(l - 1);
    ms.insert(r + 1);
    for (auto u: one) for (auto v: two) if (u + v >= l && u + v <= r) ms.insert(u + v);

    last = l - 1;
    ll ans = 0;
    for (auto x: ms) {
        ans = max(ans, x - last - 1);
        last = x;
    }

    cout << ans << endl;

    return 0;
}




