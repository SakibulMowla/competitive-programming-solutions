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


#define SZ 200010

int findMaxDist(vector <int>& dist, vector < vector <int> >& G, int u, int p) {
    dist[u] = 0;
    for (auto v: G[u]) if (v != p) {
        dist[u] = max(dist[u], 1 + findMaxDist(dist, G, v, u));
    }
    return dist[u];
}

void dfs (vector < vector <int> >& G, int u, int p, int tym, vector <int>& visit) {
    visit[u] = tym;
    for (auto v: G[u]) if (v != p) {
        dfs(G, v, u, tym + 1, visit);
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;

    vector < vector <int> > G(n + 2, vector <int> ());

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector <int> one(n + 2), two(n + 2);
    vector <int> dist(n + 2);

    findMaxDist(dist, G, 1, 1);
    dfs(G, 1, 1, 0, one);
    dfs(G, x, x, 0, two);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (two[i] < one[i]) {
            ans = max(ans, 2 * (one[i] + dist[i]));
        }
    }

    cout << ans << endl;

    return 0;
}




