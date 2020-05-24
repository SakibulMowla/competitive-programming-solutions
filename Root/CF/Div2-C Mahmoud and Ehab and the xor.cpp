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

//    cout << (1 ^ 3 ^ 4 ^ 262146 ^ 262145) << endl;

    int n, x;
    cin >> n >> x;

    if (n == 1) {
        cout << "YES" << endl;
        cout << x << endl;
    } else if (n == 2) {
        if (x == 0) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << 0 << ' ' << x << endl;
        }
    } else {
        vector<int> a(n + 1, 0);
        int _xor = 0;
        for (int i = 1; i <= n - 1; i++) {
            a[i] = i;
            _xor ^= i;
        }
        int required = x ^ _xor;
        a[n] = (required | (1 << 18));
        for (int i = 1; i <= n - 1; i++) {
            if (i != required) {
                a[i] |= (1 << 18);
                break;
            }
        }
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}





