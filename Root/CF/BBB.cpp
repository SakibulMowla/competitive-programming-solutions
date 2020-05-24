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

void dfs (int u, vector <bool>& col, vector <int>& component, vector < vector <int> >& G) {
    component.pb(u);
    col[u] = true;
    for (auto v: G[u]) {
        if (!col[v]) {
            dfs(v, col, component, G);
        }
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector < vector <int> > G(n + 1, vector <int> ());
    vector <int> deg(n + 1, 0);
    vector <bool> col(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    vector <int> component;
    bool flag = true;

    for (int i = 0; i < n && flag; i++) {
        if (!col[i]) {
            clr(component);
            dfs(i, col, component, G);
            for (int j = 0; j < sz(component); j++) {
                if (deg[component[j]] != sz(component) - 1) {
                    flag = false;
                    break;
                }
            }
        }
    }

    cout << (flag? "YES": "NO") << endl;

    return 0;
}





