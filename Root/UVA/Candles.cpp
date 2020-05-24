#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

bool possible[(1<<10)+10][110];

bool ok (int mask, int n1, int n2) {
    int col = 0;
    while (n1) {
        if (col & (1<<(n1%10))) return false;
        if ((mask & (1<<(n1%10))) == 0) return false;
        col |= (1<<(n1%10));
        n1 /= 10;
    }
    n1 = n2;
    while (n1) {
        if (col & (1<<(n1%10))) return false;
        if ((mask & (1<<(n1%10))) == 0) return false;
        col |= (1<<(n1%10));
        n1 /= 10;
    }
    return true;
}

void pre () {
    int lim = 1 << 10;
    for (int mask = 0; mask < lim; mask++) {
        for (int val = 1; val <= 100; val++) {
            for (int k = 0; k <= (val/2) + (val%2); k++) {
                if (ok(mask, k, val-k)) {
                    possible[mask][val] = 1;
                    break;
                }
            }
        }
    }
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    pre();
    int cs = 0, n, val[12];

    while (cin >> n && n) {
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }

        int lim = (1<<10);
        ll ans = 1E12;

        for (int mask = 0; mask < lim; mask++) {
            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (possible[mask][ val[i] ] == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                ll tmp = 0;
                for (int i = 9; i >= 0; i--) {
                    if (mask & (1<<i)) {
                        tmp = tmp * 10LL;
                        tmp += (ll)i;
                    }
                }
                ans = min(ans, tmp);
            }
        }

        cout << "Case " << ++cs << ": " << ans << '\n';
    }

    return 0;
}




