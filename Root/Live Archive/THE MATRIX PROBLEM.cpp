#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>

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
typedef pair <int , double> pid;
const double inf = 1E17;
const ll mod = 1LL;

#define SZ  100010

struct data {
    int city;
    double cost;
    data () {}
    data (int a, double b) {
        city = a, cost = b;
    }
    bool operator < (const data &x) const {
        return cost > x.cost;
    }
};

struct Graph {
    int n, m;
    double l, u;
    vector < vector <pid> > adj;
    vector <double> dist;
    vector <int> updated;

    Graph (int n, int m): n(n), m(m), adj(n + m + 2), dist(n + m + 2, inf), updated(n + m + 2) {
        scanf("%lf %lf", &l, &u);
        l = log(l);
        u = log(u);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                double x;
                scanf("%lf", &x);
                x = log(x);
                adj[i].pb(make_pair(j + n, u - x));
                adj[j + n].pb(make_pair(i, x - l));
            }
        }

        for (int i = 1; i <= n + m; i++) {
            adj[0].pb(make_pair(i, 0));
        }

        if (Dijkstra()) printf("YES\n");
        else printf("NO\n");
    }

    bool Dijkstra () {
        priority_queue <data> pq;
        pq.push(data(0, 0));
        dist[0] = 0;
        updated[0] = 0;

        while (!pq.empty()) {
            data u = pq.top(); pq.pop();
            for (int i = 0; i < sz(adj[u.city]); i++) {
                int v = adj[u.city][i].X;
                double w = adj[u.city][i].Y;
                if (dist[v] > dist[u.city] + w) {
                    dist[v] = dist[u.city] + w;
                    updated[v] = updated[u.city] + 1;
                    if (updated[v] > n + m + 7) {
                        return false;
                    }
                    pq.push(data(v, dist[v]));
                }
            }
        }

        return true;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        Graph Task(n, m);
    }

    return 0;
}




