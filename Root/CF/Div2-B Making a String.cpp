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

    int n;
    while (cin >> n) {
        vector <ll> a(n);
        for (auto &x: a) {
            cin >> x;
        }
        a.pb(2E9);
        sort (a.begin(), a.end());
        ll ans = 0;
        for (int i = n - 1, j = 0; i >= 0; i--, j++) {
            if (a[i] >= a[i+1]) a[i] = a[i+1] - 1;
            ans += max(0LL, a[i]);
//            ans += min(a[n - 1] - (ll)j, a[i]);
        }
        cout << ans << endl;
    }

    return 0;
}





