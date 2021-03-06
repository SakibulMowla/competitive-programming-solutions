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

int pos[SZ], apos[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, m, k;
    while (cin >> n >> m >> k) {
        for (int i = 1; i <= n; i++) {
            cin >> apos[i];
            pos[ apos[i] ] = i;
        }
        ll ans = 0;
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            ans += (ll)(pos[x]-1)/k + 1LL;
//            cout << "x = " << x << " pos[x] = " << pos[x] << ' ' << pos[x]/k + 1 << '\n';
            if (pos[x] != 1) {
                int p = pos[x];
                int y = apos[pos[x]-1];
                int q = pos[x]-1;
                apos[p] = y;
                apos[q] = x;
                pos[x] = q;
                pos[y] = p;
            }
        }
        cout << ans << '\n';
    }


    return 0;
}







