// CERC 2012
// Problem F: Farm and Factory
// Too slow solution using Bellman-Ford algorithm instead of Dijkstra's.
// Author: Adam Polak

#include <algorithm>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
const int N = 100000;
const int Q = (1 << 17) - 1;

int n;
vector<pair<int, long long> > graph[N];
long long d1[N], d2[N], x[N];
bool in_q[N];
queue<int> q;

void Bellman(int source, long long d[]) {
  for (int i=0; i<n; ++i) {
    d[i] = 1000000000000LL;
    in_q[i] = false;
  }
  d[source] = 0;
  in_q[source] = true;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    in_q[u] = false;
    q.pop();
    for (int i=0; i<graph[u].size(); ++i) {
      int v = graph[u][i].first;
      long long new_d = d[u] + graph[u][i].second;
      if (d[v] > new_d) {
        d[v] = new_d;
        if (!in_q[v]) {
          in_q[v] = true;
          q.push(v);
        }
      }
    }
  }
}

int main() {
  int Z;
  scanf("%d", &Z);
  while (Z--) {
    int m;
    scanf("%d%d", &n, &m);
    while (m--) {
      int a, b;
      long long c;
      scanf("%d%d%lld", &a, &b, &c);
      a--; b--;
      graph[a].push_back(make_pair(b, c));
      graph[b].push_back(make_pair(a, c));
    }

    Bellman(0, d1);
    Bellman(1, d2);

    long long result = 0;

    for (int k = 0; k < 2; ++k) {
      for (int i=0; i<n; ++i) x[i] = (k ? d1[i] + d2[i] : d1[i] - d2[i]);
      nth_element(x, x+(n/2), x+n);
      for (int i=0; i<n; ++i) result += labs(x[i] - x[n/2]);
    }

    printf("%0.8llf\n", result / (long double)(2 * n));

    for (int i=0; i<n; ++i) {
      vector<pair<int, long long> > temp;
      swap(temp, graph[i]);
    }
  }
  return 0;
}

