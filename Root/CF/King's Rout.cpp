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

struct Graph {
    int n, m;
    vector < vector <int> > adj;

    Graph (int n, int m): n(n), m(m), adj(n) {
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[v - 1].pb(u - 1);
        }

//        int offset;

        for (int i = 0; i < n; i++) {
            dfs(i, 0);
        }
    }

    void dfs (int u, int offset) {
        if (pos[u] != -1) {
            for (int i = 0; i < sz(adj[u]); i++) {
                int v = adj[u][i];

            }
        }
        return;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);


    return 0;
}





