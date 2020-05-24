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

int maxEdges;

int dfs (int u, int p, vector < vector <int> >& adj) {
    int degLeft = 2;
    for (auto v: adj[u]) {
        if (v == p) continue;
        int ret = dfs(v, u, adj);
        if (ret == 1 && degLeft) {
            degLeft--;
            maxEdges++;
        }
    }
    return degLeft? 1: 0;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, x, y;
    while (cin >> n >> x >> y) {
        if (x == y) {
            int u, v;
            for (int i = 0; i < n - 1; i++) {
                cin >> u >> v;
            }
            cout << (ll)x * (ll)(n - 1) << endl;
        } else if (x < y) {
            vector < vector <int> > adj(n);
            for (int i = 0; i < n - 1; i++) {
                int u, v;
                cin >> u >> v;
                adj[u-1].pb(v-1);
                adj[v-1].pb(u-1);
            }
            maxEdges = 0;
            dfs(0, -1, adj);
            cout << (ll)maxEdges * (ll)x + (ll)(n - 1 - maxEdges) * (ll)y << endl;
        } else {
            vector <int> deg(n + 1, 0);
            int u, v;
            for (int i = 0; i < n - 1; i++) {
                cin >> u >> v;
                deg[u]++;
                deg[v]++;
            }
            ll ans = (ll)y * (ll)(n - 1);
            for (int i = 0; i <= n; i++) {
                if (deg[i] == n-1) {
                    ans = ans + (ll)x - (ll)y;
                    break;
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}





