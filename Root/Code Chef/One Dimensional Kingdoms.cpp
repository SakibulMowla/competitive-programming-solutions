#include <bits/stdc++.h>

using namespace  std;

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

vector <int> a[2020], b[2020];
set <int> ms;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        for (int i = 0; i <= 2000; i++) {
            clr(a[i]);
            clr(b[i]);
        }

        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            a[l].pb(i);
            b[r].pb(i);
        }

        int ans = 0;

        for (int i = 0; i <= 2000; i++) {
            for (int j = 0; j < sz(a[i]); j++) {
                ms.insert(a[i][j]);
            }
            for (int j = 0; j < sz(b[i]); j++) {
                if (ms.find(b[i][j]) != ms.end()) {
                    ans++;
                    clr(ms);
                }
            }
        }

        cout << ans << '\n';
    }


    return 0;
}




