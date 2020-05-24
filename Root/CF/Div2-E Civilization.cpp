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

#define SZ 300010

bool vis[SZ];
bool col[SZ];
vector <int> adj[SZ];
int par[SZ];
int ans[SZ];
int _rank[SZ];

inline int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

void Union (int a, int b) {
    int x = Find(a);
    int y = Find(b);
    if (x != y) {
        if (_rank[x] > _rank[y]) par[y] = x;
        else par[x] = y;
        if (_rank[x] == _rank[y]) _rank[y]++;
    }
    return;
}

int nowcol;

pii dfs (int u) {
    col[u] = 1;
    vis[u] = nowcol;
    pii ret = {u, 0};
    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (vis[v] == !nowcol) {
            pii tmp = dfs(v);
            tmp.Y++;
            if (tmp.Y > ret.Y) {
                ret = tmp;
            }
        }
    }
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    int n, m, q;
    while (scanf("%d %d %d", &n, &m, &q) == 3) {
        for (int i = 0; i <= n; i++) {
            par[i] = i;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
            Union(a, b);
        }
        for (int i = 1; i <= n; i++) {
            if (!col[i]) {
                nowcol = 1;
                pii tmp = dfs(i);
                nowcol = 0;
                tmp = dfs(tmp.X);
                ans[ Find(i) ] = tmp.Y;
            }
        }
        for (int i = 0; i < q; i++) {
            int type;
            scanf("%d", &type);
            if (type == 1) {
                int a;
                scanf("%d", &a);
                printf("%d\n", ans[ Find(a) ]);
            } else {
                int a, b;
                scanf("%d %d", &a, &b);
                int x = Find(a);
                int y = Find(b);
                if (x != y) {
                    int tmp = ans[x]/2 + ans[x]%2 + ans[y]/2 + ans[y]%2 + 1;
                    ans[x] = ans[y] = max(tmp, max(ans[x], ans[y]));
                    Union(x, y);
                }
            }
        }
    }


    return 0;
}






