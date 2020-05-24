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
const ll mod = (1E9)+7;

#define SZ  100010

ll dp[500+2][20000+2];

void solve (int u, int p, int &M, vector < vector <int> >& adj) {
    for (int i = 1; i <= M; i++) {
        dp[u][i] = 1;
    }

    for (auto v: adj[u]) {
        if (v != p) {
            solve(v, u, M, adj);
            for (int k = 1; k <= M; k++) {
                ll tmp = 0;
                for (int j = k; j <= M; j += k) {
                    tmp += dp[v][j];
                    if (tmp >= mod) {
                        tmp -= mod;
                    }
                }
                dp[u][k] = (dp[u][k] * tmp) % mod;
            }
        }
    }

    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        vector < vector <int> > adj(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].pb(v - 1);
            adj[v - 1].pb(u - 1);
        }

        solve(0, 0, m, adj);

        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            ans += dp[0][i];
            if (ans >= mod) {
                ans -= mod;
            }
        }

        cout << ans << endl;
    }


    return 0;
}

/*
2
3 2
1 2
1 3
1 100
*/


