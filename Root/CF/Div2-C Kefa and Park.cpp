#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
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

int dfs (int u, int p, int cnt, int &m, vector < vector <int> > &adj, vector <int> &a) {
    if (cnt > m) return 0;

    int ret = 0;
    bool flag = false;

    for (auto v: adj[u]) {
        if (v != p) {
            ret += dfs(v, u, a[v]? cnt + a[v]: a[v], m, adj, a);
            flag = true;
        }
    }

    return ret + !flag;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);

    for (auto &x: a) {
        cin >> x;
    }

    vector < vector <int> > adj(n);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x - 1].pb(y - 1);
        adj[y - 1].pb(x - 1);
    }

    cout << dfs(0, 0, a[0], m, adj, a) << endl;

    return 0;
}


