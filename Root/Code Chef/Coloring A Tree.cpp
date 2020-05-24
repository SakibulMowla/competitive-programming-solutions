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
using pll = pair <ll, bool>;

const ll inf = 1;
const ll mod = 1E9 + 7;


#define SZ 52

vector <int> adj[SZ];
ll dp[SZ][SZ];

ll solve (int u, int p, int k) {
    ll &ret = dp[u][k];
    if (ret != -1) return ret;

    ret = 1;

    for (auto v: adj[u]) {
        if (v != p) {
            ll tmp = solve(v, u, k);
            if (k - 1) {
                tmp = (tmp + ((k - 1) * solve(v, u, k - 1)) % mod) % mod;
            }
            ret = (ret * tmp) % mod;
        }
    }

    return ret;
}

ll nPr[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    for (int i = 1; i <= 50; i++) {
        ll tmp = 1;
        for (int j = i, k = 1; j >= 1; j--, k++) {
            tmp = (tmp * (ll)j) % mod;
            nPr[i][k] = tmp;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
        }

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].pb(v - 1);
            adj[v - 1].pb(u - 1);
        }

        mem(dp, -1);

        cout << ((ll)k * solve(0, 0, k)) % mod << endl;
    }


    return 0;
}





