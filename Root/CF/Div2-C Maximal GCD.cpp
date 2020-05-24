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
const ll mod = 1E9 + 7;


#define SZ 10000010


int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;
    if (k > 1E6) {
        cout << -1 << endl;
    } else {
        ll k2 = k * (k + 1) / 2;
        if (k2 > n) {
            cout << -1 << endl;
        } else {
            ll gcd = 1;
            for (ll i = 1; i * i <= n; i++) {
                if (n % i != 0) continue;
                if (i <= n / k2) gcd = max(gcd, i);
                if ((n / i) <= n / k2) gcd = max(gcd, n / i);
            }
            for (ll i = 1; i < k; i++) {
                cout << i * gcd << ' ';
            }
            cout << n - (k2 - k) * gcd << endl;
        }
    }

    return 0;
}




