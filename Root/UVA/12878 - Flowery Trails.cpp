#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E8;
const ll mod = 1LL;

#define SZ 10010

int distA[SZ], distB[SZ];
vector <int> adj[SZ], cost[SZ];
priority_queue <pii, vector <pii>, greater <pii>> pq;

void dijkstra (int n, int strt, int dist[]) {
    while (!pq.empty()) pq.pop();
    for (int i = 0; i < n; i++)
        dist[i] = inf;

    dist[strt] = 0;
    pq.push(MP(0, strt));

    while (!pq.empty()) {
        pii u = pq.top();   pq.pop();

        for (int i = 0; i < sz(adj[u.Y]); i++) {
            if (dist[ adj[u.Y][i] ] > dist[u.Y] + cost[u.Y][i]) {
                dist[ adj[u.Y][i] ] = dist[u.Y] + cost[u.Y][i];
                pq.push(MP(dist[ adj[u.Y][i] ], adj[u.Y][i]));
            }
        }
    }

    return;
}

struct edge {
    int u, v, w;
};

edge E[250000+10];

int main() {
    #if defined LOCAL
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            clr(adj[i]);
            clr(cost[i]);
        }

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;

            E[i].u = u, E[i].v = v, E[i].w = w;

            adj[u].pb(v); cost[u].pb(w);
            adj[v].pb(u); cost[v].pb(w);
        }

        dijkstra(n, 0, distA);
        dijkstra(n, n-1, distB);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (distA[n-1] == distA[E[i].u] + E[i].w + distB[E[i].v] || distA[n-1] == distA[E[i].v] + E[i].w + distB[E[i].u])
                ans += E[i].w;
        }
        ans *= 2;

        cout << ans << '\n';
    }

    return 0;
}







