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

#define SZ 50010

void dfs (int u, vector <int> &adj, vector <bool> &vis) {
    vis[u] = true;
    int v = adj[u];
    if (!vis[v]) {
        dfs(v, adj, vis);
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        vector <int> adj(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            adj[i] = x - 1;
        }
        vector <bool> vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) if (!vis[i]) {
            cnt++;
            dfs(i, adj, vis);
        }
        cout << cnt - 1 << endl;
    }


    return 0;
}







