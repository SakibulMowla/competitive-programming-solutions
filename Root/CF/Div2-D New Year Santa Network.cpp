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

vector <int> adj[SZ];
vector <ll> cost[SZ];

int n;
ll cnt[SZ];
ll edge[SZ];
pii twoside[SZ];

ll dfs (int u, int p) {
    cnt[u] = 1;
    ll ret = 0;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            ret += dfs(v, u);
            cnt[u] += cnt[v];
            ret += 2LL * cost[u][i] * cnt[v] * (ll)(n - cnt[v]);
        }
    }
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].pb(b);
        adj[b].pb(a);

        cost[a].pb(c);
        cost[b].pb(c);

        edge[i+1] = c;
        twoside[i+1] = {a, b};
    }

    ll ans = dfs(1, -1);

    int m;
    cin >> m;

    cout << fixed << setprecision(12);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        int c = min(cnt[twoside[a].X], cnt[twoside[a].Y]);
        ans -= 2LL * (edge[a] - (ll)b) * (ll)c * (ll)(n - c);
        edge[a] = b;

        cout << 3.0 * ans / (double)n / (double)(n-1) << '\n';
    }

    return 0;
}







