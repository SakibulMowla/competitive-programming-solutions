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

    ll n, a;
    cin >> n >> a;

    vector <ll> v(n);
    for (auto &x: v) {
        cin >> x;
    }
    sort(v.begin(), v.end());

    if (n == 1) {
        cout << 0 << endl;
    } else {
        ll d1 = (v[0] < a ? (a - v[0]): 0);
        ll d2 = (v[1] < a ? (a - v[1]): 0);
        ll d3 = (v[n - 2] > a ? (v[n - 2] - a): 0);
        ll d4 = (v[n - 1] > a ? (v[n - 1] - a): 0);
        ll ans = min(2 * d1 + d3, min(2 * d2 + d4, min(2 * d4 + d2, 2 * d3 + d1)));
        cout << ans << endl;
    }


    return 0;
}





