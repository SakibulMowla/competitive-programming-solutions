#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  500010

int dp[SZ][2];

int dfs (int u, int p, int pre, vector <int> &a, vector < vector <int> > &adj) {
    int &ret = dp[u][pre];
    if (ret != -1) return ret;

    int tmp = 0;
    for (auto v: adj[u]) {
        if (v != p) {
            tmp += dfs(v, u, 1, a, adj);
        }
    }
    if (!a[u]) tmp++;
    ret = tmp;

    if (pre) {
        tmp = 0;
        for (auto v: adj[u]) {
            if (v != p) {
                tmp += dfs(v, u, a[u], a, adj);
            }
        }
        ret = min(ret, tmp);
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i][0] = dp[i][1] = -1;
        }

        vector < vector <int> > adj(n);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            adj[u-1].pb(v-1);
            adj[v-1].pb(u-1);
        }

        cout << min(dfs(0, 0, 1, a, adj), dfs(0, 0, 0, a, adj)) << endl;
    }

    return 0;
}



