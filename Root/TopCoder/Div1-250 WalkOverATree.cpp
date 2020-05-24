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

class WalkOverATree {
public:
    int dfs (vector < vector <int> > &adj, int u, int p) {
        int ret = 0;
        for (auto v: adj[u]) {
            if (v == p) continue;
            ret = max(ret, 1 + dfs(adj, v, u));
        }
        return ret;
    }
	int maxNodesVisited(vector <int> parent, int L) {
	    int n = sz(parent) + 1;
	    vector < vector <int> > adj(n);
	    for (int i = 0; i < sz(parent); i++) {
            adj[i+1].pb(parent[i]);
            adj[parent[i]].pb(i+1);
	    }
	    int dep = dfs(adj, 0, 0);
        if (L <= dep) {
            return 1 + L;
        } else if (2 * (n - 1) - dep <= L) {
            return n;
        } else {
            return 1 + dep + (L - dep) / 2;
        }
	}
};
