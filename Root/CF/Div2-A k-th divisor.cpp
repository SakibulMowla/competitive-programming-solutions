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

    ll n, k;
    cin >> n >> k;

    vector <ll> v;

    ll i;
    for (i = 1; i * i < n; i++) {
        if (n % i == 0) {
            v.pb(i);
            v.pb(n / i);
        }
    }
    if (i * i == n) {
        v.pb(i);
    }

    sort(v.begin(), v.end());

    if (k > sz(v)) cout << -1 << endl;
    else cout << v[k-1] << endl;

    return 0;
}





