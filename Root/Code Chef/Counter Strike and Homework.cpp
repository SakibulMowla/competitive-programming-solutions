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

void dfs (int u, int p, vector < vector<int> >& adj, vector < vector<ll> >& cost, vector <int>& cnt, vector <ll>& dp) {
    cnt[u] = 1;
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            dfs(v, u, adj, cost, cnt, dp);
            dp[u] += cost[u][i] * (ll)cnt[v] + dp[v];
            cnt[u] += cnt[v];
        }
    }

    return;
}

int n;

void solve (int u, int p, ll exact, vector < vector<int> >& adj, vector < vector<ll> >& cost, vector <int>& cnt, vector <ll>& dp) {
    if (u) {
        ll ans = dp[p];
        ans -= dp[u];
        ans -= exact * (ll)cnt[u];
        ans += exact * (ll)(n - cnt[u]);
        dp[u] += ans;
    }

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (v != p) {
            solve(v, u, cost[u][i], adj, cost, cnt, dp);
        }
    }

    return;
}

int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> n;

        vector < vector <int> > adj(n);
        vector < vector <ll> > cost(n);
        vector <int> cnt(n, 0);
        vector <ll> dp(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            ll w;
            cin >> u >> v >> w;
            adj[u - 1].pb(v - 1);
            adj[v - 1].pb(u - 1);
            cost[u - 1].pb(w);
            cost[v - 1].pb(w);
        }

        dfs(0, 0, adj, cost, cnt, dp);
        solve(0, 0, 0, adj, cost, cnt, dp);

        for (int i = 0; i < n; i++) {
            cout << dp[i] << endl;
        }
    }


    return 0;
}


