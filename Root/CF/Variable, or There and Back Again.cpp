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
    vector < vector <int> > adj, rev;
    vector <int> val;
    vector <bool> vis;
    vector <int> cnt;

    Graph (int n, int m): n(n), m(m), adj(n), rev(n), val(n), vis(n, false), cnt(n, 0) {
        for (int i = 0; i < n; i++) {
            cin >> val[i];
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].pb(v - 1);
            rev[v - 1].pb(u - 1);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i] && val[i] == 1) {
                one(i);
            }
        }

        vis = vector <bool>(n, false);

        for (int i = 0; i < n; i++) {
            if (!vis[i] && val[i] == 2) {
                two(i);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << (cnt[i] == 2 ? 1 : 0) << endl;
        }
    }

    void one (int u) {
        cnt[u]++;
        vis[u] = true;
        for (int i = 0; i < sz(adj[u]); i++) {
            int v = adj[u][i];
            if (!vis[v] && val[v] != 1) {
                one(v);
            }
        }
        return;
    }

    void two (int u) {
        cnt[u]++;
        vis[u] = true;
        if (val[u] == 1) return;
        for (int i = 0; i < sz(rev[u]); i++) {
            int v = rev[u][i];
            if (!vis[v]) {
                two(v);
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

    int n, m;
    cin >> n >> m;

    Graph Task(n, m);

    return 0;
}




