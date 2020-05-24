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

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d %d", &n, &m);

    int colors = 1;
    vector < vector <int> > mset(n, vector <int> ());
    vector < vector <int> > G(n, vector <int> ());

    for (int i = 0; i < n; i++) {
        int lim;
        scanf("%d", &lim);
        for (int j = 0; j < lim; j++) {
            int x;
            scanf("%d", &x);
            mset[i].pb(x - 1);
        }
        colors = max(colors, lim);
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u - 1].pb(v - 1);
        G[v - 1].pb(u - 1);
    }

    set <int> ms;
    vector <int> col(m, 0);
    vector <bool> vis(n, false);
    queue <int> Q;

    Q.push(0);
    vis[0] = true;

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto j: mset[u]) {
            if (col[j] != 0)
                ms.insert(col[j]);
        }
        int now = 1;
        for (auto j: mset[u]) {
            if (col[j] == 0) {
                while (ms.find(now) != ms.end()) now++;
                col[j] = now;
                now++;
            }
        }
        for (auto v: G[u]) {
            if (!vis[v]) {
                vis[v] = true;
                Q.push(v);
            }
        }
        ms.clear();
    }

    printf("%d\n", colors);
    for (int i = 0; i < m; i++) {
        if (col[i] == 0) col[i] = 1;
        printf("%d ", col[i]);
    }
    printf("\n");

    return 0;
}
