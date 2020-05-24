#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

ll f[110];

int main() {
//    #if defined JESI
        freopen("bubble.in", "r", stdin);
        freopen("bubble.out", "w", stdout);
//    #endif

    f[1] = f[2] = 1;
    for (int i = 3; i <= 64; i++) {
        f[i] = 2LL * f[i-1];
    }

    int n;
    ll k;
    while (cin >> n >> k && (n || k)) {
//        assert(n <= 64);
        int lft = n;
        bool flag = false;

        for (int i = 1; n - i >= 64; i++) {
            if (flag) cout << ' ';
            else flag = true;
            cout << i;
            lft--;
        }

        vector <int> v;

        if (n <= 64) {
            for (int i = 1; i <= n; i++) {
                v.pb(i);
            }
        } else {
            for (int i = 63; i >= 0; i--) {
                v.pb(n - i);
            }
        }

        while (lft) {
            if (f[lft] >= k) {
                if (flag) cout << ' ';
                else flag = true;
                cout << v[0] << ' ';
                v.erase(v.begin() + 0);
                lft--;
            } else {
                int t = lft;
                while (k - f[t] > 0) {
                    k -= f[t];
                    t--;
                }
//                cerr << "lft = " << lft << " t = " << t << endl;
                if (flag) cout << ' ';
                else flag = true;
                cout << v[lft-t] << ' ';
                v.erase(v.begin() + (lft-t));
                lft--;
            }
        }

        cout << endl;
    }

    return 0;
}







