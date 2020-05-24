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

    ll x;
    while (cin >> x) {
        if (x <= 2) {
            cout << -1 << endl;
        } else {
            ll m, n, b, c;
            if (x % 2 == 0) {
                m = x / 2, n = 1;
                b = m * m + n * n;
                c = m * m - n * n;
            } else {
                m = (x + 1) / 2, n = (x - 1) / 2;
                b = m * m + n * n;
                c = 2 * m * n;
            }
            cout << b << ' ' << c << endl;
        }
    }


    return 0;
}





