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
const ll inf = 1E16;
const ll mod = 1E9;

#define SZ 300010

struct data {
    int to, num;
    ll weight;
    data (int a, ll b, int c) {
        to = a, weight = b, num = c;
    }
    bool operator < (const data &x) const {
        return weight > x.weight;
    }
};

vector <data> adj[SZ];
ll dist[SZ];

void dijkstra (int n, int strt) {
    priority_queue <data> pq;
    for (int i = 0; i <= n; i++) {
        dist[i] = inf;
    }

    dist[strt] = 0;
    pq.push(data(strt, 0, 0));

    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < sz(adj[u.to]); i++) {
            int v = adj[u.to][i].to;
            if (dist[v] > u.weight + adj[u.to][i].weight) {
                dist[v] = u.weight + adj[u.to][i].weight;
                pq.push(data(v, dist[v], 0));
            }
        }
    }

    return;
}

ll tot;
vector <int> ans;

void solve (int n, int u) {
    for (int i = 1; i <= n; i++) {
        if (i == u) continue;
        ll mn = 1E16;
        int idx;
        for (int j = 0; j < sz(adj[i]); j++) {
            int v = adj[i][j].to;
            ll cost = adj[i][j].weight;
            if (dist[i] == dist[v] + cost) {
                if (cost < mn) {
                    mn = cost;
                    idx = adj[i][j].num;
                }
            }
        }
        ans.pb(idx);
        tot += mn;
    }
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
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb(data(v, w, i));
        adj[v].pb(data(u, w, i));
    }

    int u;
    cin >> u;

    dijkstra(n, u);
    solve(n, u);

    cout << tot << endl;
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;

    return 0;
}




