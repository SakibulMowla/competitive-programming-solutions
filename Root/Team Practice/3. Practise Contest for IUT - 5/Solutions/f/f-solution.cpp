// CERC 2012
// Problem F: Farm and factory
// Model solution, O(n + m log n)
// Author: Jakub Pachocki

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long LL;

struct Entry {
    int vertex;
    LL cost;

    Entry() {
    }

    Entry(int _vertex, LL _cost) :
        vertex(_vertex),
        cost(_cost) {
    }
};

struct Edge {
    int dest;
    int cost;

    Edge() {
    }

    Edge(int _dest, int _cost) :
        dest(_dest),
        cost(_cost) {
    }
};

bool operator < (const Entry& a, const Entry& b) {
    return a.cost > b.cost;
}

vector<LL> get_dists(int source, const vector<vector<Edge> >& e) {
    static const LL INF = (LL) 1e18l;
    int n = e.size();
    vector<LL> dist(n, INF);
    dist[source] = 0;
    priority_queue<Entry> q;
    q.push(Entry(source, 0));
    while (!q.empty()) {
        int c = q.top().vertex;
        LL cost = q.top().cost;
        q.pop();
        if (cost > dist[c]) {
            continue;
        }
        for (vector<Edge>::const_iterator it = e[c].begin(); it != e[c].end(); ++it) {
            LL cur_cost = cost + it->cost;
            if (dist[it->dest] > cur_cost) {
                dist[it->dest] = cur_cost;
                q.push(Entry(it->dest, cur_cost));
            }
        }
    }
    return dist;
}

LL get_dev(vector<LL> v) {
    int n = v.size();
    sort(v.begin(), v.end());
    return accumulate(v.begin() + (n + 1) / 2, v.end(), 0LL) - accumulate(v.begin(), v.begin() + n / 2, 0LL);
}

void alg() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge> > e(n);
    for (int i = 0; i < m; ++i) {
        int u, v, cost;
        cin >> u >> v >> cost;
        --u;
        --v;l
        e[u].push_back(Edge(v, cost));
        e[v].push_back(Edge(u, cost));
    }
    vector<LL> d0 = get_dists(0, e);
    vector<LL> d1 = get_dists(1, e);
    vector<LL> x, y;
    for (int i = 0; i < n; ++i) {
        x.push_back(d0[i] + d1[i]);
        y.push_back(d0[i] - d1[i]);
    }
    cout << fixed;
    cout << setprecision(12);
    cout << (get_dev(x) + get_dev(y)) / (long double) (2 * n) << endl;
}

int main() {
    int n_testcases;
    cin >> n_testcases;
    for (int testcase = 0; testcase < n_testcases; ++testcase) {
        alg();
    }
}
