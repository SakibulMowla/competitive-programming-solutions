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

    vector <int> x, m(5), w(5);
    x.pb(500);
    x.pb(1000);
    x.pb(1500);
    x.pb(2000);
    x.pb(2500);

    for (int i = 0; i < 5; i++) {
        cin >> m[i];
    }
    for (int i = 0; i < 5; i++) {
        cin >> w[i];
    }

    int hs, hu;
    cin >> hs >> hu;

    int ans = 100 * hs - 50 * hu;

    for (int i = 0; i < 5; i++) {
        ans += max(3 * (x[i] / 10), x[i] - m[i] * (x[i] / 250) - 50 * w[i]);
    }

    cout << ans << endl;

    return 0;
}





