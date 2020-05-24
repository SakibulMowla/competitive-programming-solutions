#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  3010

struct data {
    int city, cost, costR, costT;
    data () {}
    data (int a, int b, int c, int d) {
        city = a, cost = b, costR = c, costT = d;
    }
    bool operator < (const data& p) const {
        return cost > p.cost;
    }
};

vector <data> adj[SZ];
int dist[SZ], dist1[SZ];

void dijkstra (int strt, int dest, int n) {
    for (int i = 0; i <= n; i++) {
        dist[i] = 1E9;
    }
    dist[strt] = 0;

    priority_queue <data> pq;
    pq.push(data(strt, 0, 0, 0));

    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < sz(adj[u.city]); i++) {
            int v = adj[u.city][i].city;
            if (dist[v] > dist[u.city] + adj[u.city][i].costR) {
                dist[v] = dist[u.city] + adj[u.city][i].costR;
                pq.push(data(v, dist[v], 0, 0));
            }
        }
    }

    return;
}

void dijkstra1 (int strt, int dest, int n) {
    for (int i = 0; i <= n; i++) {
        dist1[i] = 1E9;
    }
    dist1[strt] = 0;

    priority_queue <data> pq;
    pq.push(data(strt, 0, 0, 0));

    while (!pq.empty()) {
        data u = pq.top(); pq.pop();
        for (int i = 0; i < sz(adj[u.city]); i++) {
            int v = adj[u.city][i].city;
            if (dist1[v] > dist1[u.city] + adj[u.city][i].costR) {
                dist1[v] = dist1[u.city] + adj[u.city][i].costR;
                pq.push(data(v, dist1[v], 0, 0));
            }
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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i <= n; i++) {
            clr(adj[i]);
        }

        vector <data> info;
        for (int i = 0; i < m; i++) {
            int u, v, r, t;
            cin >> u >> v >> r >> t;
            adj[u].pb(data(v, 0, r, t));
            adj[v].pb(data(u, 0, r, t));
            info.pb(data(u, v, r, t));
        }

        int strt, dest;
        cin >> strt >> dest;

        dijkstra(strt, dest, n);
        dijkstra1(dest, strt, n);

        int ans = dist[dest];
        for (int i = 0; i < m; i++) {
            ans = min(ans, dist[info[i].city] + info[i].costT + dist1[info[i].cost]);
            ans = min(ans, dist[info[i].cost] + info[i].costT + dist1[info[i].city]);
        }

        cout << (ans >= 1E9 ? -1: ans) << endl;
    }

    return 0;
}



