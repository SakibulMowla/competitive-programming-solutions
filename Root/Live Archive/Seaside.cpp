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
const ll inf = 1E17;
const ll mod = 1LL;

#define SZ  100010

struct data {
    int city, cost;
    data () {}
    data (int a, int b) {
        city = a, cost = b;
    }
    bool operator < (const data &x) const {
        return cost > x.cost;
    }
};

struct Graph {
    int n;
    vector < vector <pll> > adj;
    vector <int> mark;
    vector <ll> dist;

    Graph (int n): n(n), adj(n), mark(n), dist(n, inf) {
        for (int i = 0; i < n; i++) {
            int x, p;
            cin >> x >> p;
            for (int j = 0; j < x; j++) {
                ll v, w;
                cin >> v >> w;
                adj[i].pb(make_pair(v, w));
            }
            mark[i] = p;
        }

        Dijkstra();

        ll ans = inf;
        for (int i = 0; i < n; i++) {
            if (mark[i]) {
                ans = min(ans, dist[i]);
            }
        }

        cout << ans << endl;
    }

    void Dijkstra () {
        priority_queue <data> pq;
        pq.push(data(0, 0));
        dist[0] = 0;

        while (!pq.empty()) {
            data u = pq.top(); pq.pop();
            for (int i = 0; i < sz(adj[u.city]); i++) {
                int v = adj[u.city][i].X;
                ll w = adj[u.city][i].Y;
                if (dist[v] > dist[u.city] + w) {
                    dist[v] = dist[u.city] + w;
                    pq.push(data(v, dist[v]));
                }
            }
        }

        return;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        Graph Task(n);
    }

    return 0;
}




