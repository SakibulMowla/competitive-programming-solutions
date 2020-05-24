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


#define SZ 200010

ll dist[SZ][6];

ll dfs (int u, int p, vector < vector <int> >& G, int k) {
    ll ans = 0;

    dist[u][0] = 1;
    for (auto v: G[u]) {
        if (v != p) {
            ans += dfs(v, u, G, k);
            for (int i = 1; i <= k; i++) {
                dist[u][i] += dist[v][i - 1];
            }
        }
    }

    vector <ll> dp(k + 1, 0), dpNow(k + 1, 0);

    for (auto v: G[u]) {
        if (v != p) {
            dpNow = dp;
            for (int i = 1; i <= k; i++) {
                dpNow[i] += dist[v][i - 1];
                for (int j = 1; i + j <= k; j++) {
                    dpNow[i + j] = dp[j] * dist[v][i - 1];
                }
            }
            dp = dpNow;
        }
    }

    for (int i = 1; i <= k; i++) {
        ans += (ll)i * dp[i];
    }

    cout << ">> u = " << u << " ans = " << ans << endl;

    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < vector <int> > G(n + 1, vector <int> ());

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    cout << dfs(1, 1, G, k) << endl;

    return 0;
}





