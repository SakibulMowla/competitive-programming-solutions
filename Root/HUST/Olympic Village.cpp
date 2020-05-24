#include "bits/stdc++.h"

using namespace std;

typedef unsigned long long ll;

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

ll a[SZ];
ll b[SZ];
int x[SZ];
ll type[SZ];
ll sum[SZ];

set <ll> ms;

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int k, m;
        cin >> k >> m;

        int xcnt = 0;
        clr(ms);
        for (int i = 1; i <= k; i++) {
            cin >> a[i] >> b[i];
            ms.insert(a[i]);
            ms.insert(b[i]);
//            x[xcnt++] = a[i];
//            x[xcnt++] = b[i];
        }
        mem(type, 0);
        for (int i = 0; i < m; i++) {
            int d;
            cin >> d;
            for (int j = 0; j < d; j++) {
                int u;
                ll v;
                cin >> u >> v;
                type[u] += v;
            }
        }

//        cout << "> xcnt = " << xcnt << '\n';

//        sort(x, x+xcnt);
//        xcnt = unique(x, x+xcnt) - x;
        map <ll, int> mp;
        int cnt = 0;
        for (set <ll> ::iterator it = ms.begin(); it != ms.end(); it++) {
            mp[ *it ] = ++cnt;
        }
//        cout << "> xcnt = " << xcnt << '\n';

        for (int i = 1; i <= k; i++) {
//            cout << a[i] << " " << b[i] << '\n';
//            a[i] = (lower_bound(x, x+xcnt, a[i]) - x) + 1;
//            b[i] = (lower_bound(x, x+xcnt, b[i]) - x) + 1;
//            cout << a[i] << " " << b[i] << '\n';
            a[i] = mp[ a[i] ];
            b[i] = mp[ b[i] ];
        }

        mem(sum, 0);
        for (int i = 1; i <= k; i++) {
            for (int j = a[i]; j <= b[i]; j++) {
                sum[j] += type[i];
            }
        }

        ll ans = 0;
        for (int i = 1; i <= sz(ms); i++) {
            ans = max(ans, sum[i]);
        }

        cout << "Case " << cs + 1 << ": " << ans << '\n';

        assert(sz(ms) <= 60);
    }

    return 0;
}




