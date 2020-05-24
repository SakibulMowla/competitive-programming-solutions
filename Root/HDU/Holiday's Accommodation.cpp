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

vector <int> adj[SZ], cost[SZ];
int child[SZ];
int par[SZ];
bool col[SZ];

ll solve (int n) {
    queue <int> Q;
    vector <int> a;

    mem(col, 0);
    Q.push(1);
    par[1] = 0;
    col[1] = 1;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        a.pb(u);
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i];
            if (!col[v]) {
                par[v] = u;
                col[v] = 1;
                Q.push(v);
            }
        }
    }

    mem(child, 0);
    for (int i = n - 1; i >= 0; i--) {
        int u = a[i];
        child[u]++;
        child[par[u]] += child[u];
    }

    ll ans = 0LL;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < sz(adj[i]); j++) {
            int v = adj[i][j];
            if (v != par[i]) {
                ans += 2LL * (ll)cost[i][j] * (ll)min(child[v], n - child[v]);
            }
        }
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            clr(adj[i]);
            clr(cost[i]);
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].pb(v);
            adj[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        cout << "Case #" << cs + 1 << ": " << solve(n) << endl;
    }


    return 0;
}







