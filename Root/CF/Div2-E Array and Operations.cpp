#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010


const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
	Edge &e = G[x][i];
	if (!dad[e.to] && e.cap - e.flow > 0) {
	  dad[e.to] = &G[x][i];
	  Q[tail++] = e.to;
	}
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	if (!e) { amt = 0; break; }
	amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
	e->flow += amt;
	G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};



bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(SZ);
    for (int i = 3; i <= k; i += 2)
        if (!arr[i])
            for (ll j = (ll)i * (ll)i; j < SZ; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime.pb(i);
}

map <int , int> mp;
vector <pii> v[110];

void factorize (int n) {
    int N = n;
    for (int i = 0; i < sz(prime) && (ll)prime[i] * (ll)prime[i] <= (ll)n; i++) {
        if (n % prime[i] == 0) {
            int j = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                ++j;
            }
            v[ mp[N] ].pb(MP(prime[i], j));
        }
    }
    if (n != 1) {
        v[ mp[N] ].pb(MP(n, 1));
    }
    return;
}

int a[110];
int b[110];
int c[110];

map <pii, int> mpp;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    sieve();

    int n, m;
    cin >> n >> m;

    int node = 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) {
            mp[ a[i] ] = sz(mp);
            factorize(a[i]);
        }
        node += sz(v[ mp[a[i]] ]);
    }

    Dinic din(node);

    int cnt = 1;

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 0; j < sz(v[ mp[a[i]] ]); j++) {
                mpp[ MP(i, j) ] = ++cnt;
                din.AddEdge(0, cnt, v[ mp[a[i]] ][j].Y);
            }
        } else {
            for (int j = 0; j < sz(v[ mp[a[i]] ]); j++) {
                mpp[ MP(i, j) ] = ++cnt;
                din.AddEdge(cnt, 1, v[ mp[a[i]] ][j].Y);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i] >> c[i];
        if (b[i] % 2 == 0)
            swap(b[i], c[i]);

        for (int j = 0; j < sz(v[ mp[ a[ b[i] ] ] ]); j++) {
            for (int k = 0; k < sz(v[ mp[ a[ c[i] ] ] ]); k++) {
                if (v[ mp[ a[ b[i] ] ] ][j].X == v[ mp[ a[ c[i] ] ] ][k].X) {
                    din.AddEdge(mpp[MP(b[i], j)], mpp[MP(c[i], k)], min(v[ mp[ a[ b[i] ] ] ][j].Y, v[ mp[ a[ c[i] ] ] ][k].Y));
                }
            }
        }
    }

    cout << din.GetMaxFlow(0, 1) << '\n';


    return 0;
}






