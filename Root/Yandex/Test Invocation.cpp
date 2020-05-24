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

    int n;
    cin >> n;

    vector < vector <int> > G(n + 1, vector <int> ());
    vector <ll> a(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            G[i].pb(v);
        }
    }

    vector <int> lev(n + 1, 0);
    queue <int> q;

    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: G[u]) {
            q.push(v);
            lev[v] = lev[u] + 1;
        }
    }

    ll sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += a[i] * (1LL << lev[i]);
        sum += a[i];
    }

    cout << sum << ' ' << ans << endl;

    return 0;
}





