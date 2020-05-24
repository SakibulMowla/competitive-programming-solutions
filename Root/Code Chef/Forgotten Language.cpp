#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        vector <string> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector <bool> f(n, false);

        for (int i = 0; i < k; i++) {
            int l;
            cin >> l;
            for (int j = 0; j < l; j++) {
                string s;
                cin >> s;
                for (int p = 0; p < n; p++) {
                    if (s == a[p]) {
                        f[p] = true;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (i) cout << ' ';
            if (f[i]) cout << "YES";
            else cout << "NO";
        }

        cout << endl;
    }


    return 0;
}




