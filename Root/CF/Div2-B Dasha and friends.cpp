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


#define SZ 1010

int a[SZ], b[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = n - 1; i > 0; i--) {
        b[i] -= b[i-1];
    }

    for (int i = 2 * n - 1; i > 0; i--) {
        a[i] = (a[i] - a[i-1] + l) % l;
    }

    if (n == 1) {
        cout << "YES" << endl;
    } else {
        bool flag = false;
        for (int strt = 0; strt < n; strt++) {
            int k;
            for (k = 1; k < n; k++) {
                if (b[k] != a[k + strt]) break;
            }
            if (k == n) {
                flag = true;
                break;
            }
        }
        cout << (flag? "YES": "NO") << endl;
    }

    return 0;
}





