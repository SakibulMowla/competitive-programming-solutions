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
const ll mod = 1000000007;

#define SZ  100010

void dfs (int u, int p, vector < vector <int> >& adj, vector <char>& col, vector <ll>& cnt) {
    cnt[u] = 1;
    for (auto v: adj[u]) {
        if (v != p) {
            dfs(v, u, adj, col, cnt);
            if (col[v] != col[u]) {
                cnt[u] += cnt[v];
            }
        }
    }
    return;
}

ll solve (int u, int p, vector < vector <int> >& adj, vector <char>& col, vector <ll>& cnt) {
    ll ans = 1;
    ll pre = 0;
    for (auto v: adj[u]) {
        if (v != p) {
            ans = (ans + solve(v, u, adj, col, cnt)) % mod;
            if (col[v] != col[u]) {
                ans = (ans + cnt[v]) % mod;
                ans = (ans + (pre * cnt[v]) % mod) % mod;
                pre += cnt[v];
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

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector < vector <int> > adj(n);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].pb(v - 1);
        adj[v - 1].pb(u - 1);
    }

    vector <char> col(n);
    vector <ll> cnt(n, 0);

    for (auto &x: col) {
        cin >> x;
    }

    dfs(0, 0, adj, col, cnt);
    cout << solve(0, 0, adj, col, cnt) << endl;

    return 0;
}




