#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

vector <int> adj[SZ];
int val[SZ];
bool col[SZ];
int last;

int dfs (int u) {
//    cout << ">> u = " << u << '\n';
    col[u] = 1;
    last = u;

    int best = -1E8, that = -1, ret = val[u];

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (col[v]) continue;
        if (val[v] > best) {
            best = val[v];
            that = v;
        }
    }

    if (that != -1) {
        ret += dfs(that);
    }

    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            cin >> val[i];
            clr(adj[i]);
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
        }

        mem(col, 0);

        cout << "Case " << cs + 1 << ": " << dfs(0);
        cout << " " << last << '\n';
    }


    return 0;
}




