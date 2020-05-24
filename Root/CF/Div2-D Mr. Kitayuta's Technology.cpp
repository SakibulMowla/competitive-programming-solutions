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

vector <int> adj[SZ];
vector <int> G[SZ];
bool col[SZ];
bool visited[SZ];
bool now[SZ];

void dfs (int u, int &cnt, vector <int> &vv) {
    col[u] = 1;
    vv.pb(u);
    cnt++;

    for (int i = 0; i < sz(adj[u]); i++) {
        int v = adj[u][i];
        if (!col[v]) {
            dfs(v, cnt, vv);
        }
    }

    return;
}

void dfs2 (int u, bool &cycle) {
    visited[u] = 1;
    now[u] = 1;

    for (int i = 0; i < sz(G[u]); i++) {
        int v = G[u][i];
        if (!visited[v]) {
            dfs2(v, cycle);
        } else if (now[v]) {
            cycle = true;
        }
    }

    now[u] = 0;
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        G[a].pb(b);
    }

    int ans = 0;
    int cnt;
    bool cycle;

    vector <int> v;

    for (int i = 1; i <= n; i++) {
        if (!col[i]) {
            cnt = 0;
            cycle = 0;
            clr(v);
            dfs(i, cnt, v);
            for (int j = 0; j < sz(v); j++) {
                if (!visited[v[j]]) {
                    dfs2 (v[j], cycle);
                    if (cycle) {
                        break;
                    }
                }
            }
            ans += cnt - 1 + cycle;
        }
    }

    cout << ans << '\n';


    return 0;
}






