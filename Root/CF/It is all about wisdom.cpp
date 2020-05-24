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

struct data {
    int to;
    ll cost, val;
    data () {}
    data (int to, ll cost, ll val): to(to), cost(cost), val(val) {}
    bool operator < (const data& x) const {
        return cost > x.cost;
    }
};

struct Graph {
    int n, m;
    ll k;
    vector < vector <data> > adj;

    Graph (int n, int m, ll k): n(n), m(m), k(k), adj(n) {
        for (int i = 0; i < m; i++) {
            int u, v;
            ll cost, val;
            cin >> u >> v >> cost >> val;
            adj[u - 1].pb(data(v - 1, cost, val));
            adj[v - 1].pb(data(u - 1, cost, val));
        }

        ll lo = 0;
        ll hi = 1E9;
        int ans = -1;

        while (lo <= hi) {
            ll mid = (lo + hi) >> 1;
            if (bfs(mid) < k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << ans << endl;
    }

    ll bfs (ll mid) {
        priority_queue <data> pq;
        vector <ll> dist(n + 2, numeric_limits<ll>::max());

        dist[0] = 0;
        pq.push(data(0, 0, 0));

        while (!pq.empty()) {
            data u = pq.top(); pq.pop();
            for (int i = 0; i < sz(adj[u.to]); i++) {
                int v = adj[u.to][i].to;
                if (dist[v] > dist[u.to] + adj[u.to][i].cost && adj[u.to][i].val <= mid) {
                    dist[v] = dist[u.to] + adj[u.to][i].cost;
                    pq.push(data(v, dist[v], 0));
                }
            }
        }

        return dist[n-1];
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        ll k;
        cin >> n >> m >> k;

        Graph Task(n, m, k);
    }


    return 0;
}





