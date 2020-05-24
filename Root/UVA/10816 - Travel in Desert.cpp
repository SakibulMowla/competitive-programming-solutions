#include <vector>
#include <iostream>
#include <queue>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Edge {
    int x, y;
    double r, d;
    Edge() {}
    Edge(int x, int y, double r, double d) :
        x(x),  y(y), r(r), d(d) {}
    bool operator < (const Edge& edge) const {
        return r < edge.r;
    }
};

struct Node {
    int city;
    double cost, temp;
    Node(int city, double cost, double temp) :
        city(city), cost(cost), temp(temp) {}
    bool operator < (const Node& node) const {
        return cost < node.cost;
    }
};

struct Solution {
    int n, e;
    int s, t;
    vector<Edge> Paths;
    vector<vector<Node>> G;
    vector<int> par;
    vector<int> dist;

    Solution(int n, int e) :
        n(n),
        e(e),
        Paths(e),
        G(n + 1, vector<Node>()),
        par(n + 1),
        dist(n + 1) {
        cin >> s >> t;
        for (auto& path: Paths) {
            cin >> path.x >> path.y >> path.r >> path.d;
            path.d *= 10;
        }
        sort(Paths.begin(), Paths.end());
        for (auto& path: Paths) {
            G[path.x].push_back(Node(path.y, path.d, path.r));
            G[path.y].push_back(Node(path.x, path.d, path.r));
        }
        int lo = 0, hi = e - 1, ans = numeric_limits<int>::max();
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (dijkstra(mid) != numeric_limits<int>::max()) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (ans != numeric_limits<int>::max()) {
            int len = dijkstra(ans);
            vector<int> route;
            route.push_back(t);
            while (par[t] != -1) {
                t = par[t];
                route.push_back(t);
            }
            reverse(route.begin(), route.end());
            for (int i = 0; i < route.size(); i++) {
                if (i) cout << ' ';
                cout << route[i];
            }
            cout << endl;
            cout << fixed << setprecision(1) << len / 10.0 << ' ' << Paths[ans].r << endl;
        } else {
            cout << "No path found!!!" << endl;
        }
    }

    int dijkstra(int lim) {
        fill(par.begin(), par.end(), -1);
        fill(dist.begin(), dist.end(), numeric_limits<int>::max());

        priority_queue<Node> pq;
        dist[s] = 0;
        pq.push(Node(s, 0, 0));

        while (!pq.empty()) {
            auto u = pq.top();
            pq.pop();
            for (auto v: G[u.city]) {
                if (v.temp > Paths[lim].r) break;
                if (dist[v.city] > dist[u.city] + v.cost) {
                    dist[v.city] = dist[u.city] + v.cost;
                    par[v.city] = u.city;
                    pq.push(Node(v.city, dist[v.city], 0));
                }
            }
        }

        return dist[t];
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n, e;
    while (cin >> n >> e) {
        Solution sol(n, e);
    }

    return 0;
}