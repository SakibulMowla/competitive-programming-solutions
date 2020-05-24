#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

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

const ll inf = 1;
const ll mod = 1E9;

#define SZ 110

ll mul (ll a, ll b, ll mod) {
    ll ret = 0;
    while (b) {
        if (b & 1) {
            ret += a;
            if (ret >= mod)
                ret -= mod;
        }
        a = a << 1;
        if (a >= mod)
            a -= mod;
        b = b >> 1;
    }
    return ret;
}

bool isPrime (ll a, ll n) {
    ll x = 1, step = 1LL << 60, rx;
    while (step > n - 1) {
        step >>= 1;
    }
    while (step > 0) {
        rx = mul(x, x, n);
        if (rx == 1 && x != 1 && x != n - 1)
            return 0;
        x = rx;
        if (step & (n - 1))
            x = mul(x, a, n);
        step >>= 1;
    }
    return (x == 1);
}

bool isPrime (ll n) {
    if (n < 100) {
        for (int i = 2; i < n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    return isPrime(2, n) && isPrime(7, n) && isPrime(61, n) && isPrime(13, n);
}

const int INF = 2E9;

struct Edge {
    int from, to, cap, flow, index;
    Edge (int from, int to, int cap, int flow, int index) : from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
    int N;
    vector < vector <Edge> > G;
    vector <Edge *> dad;
    vector <int> Q;

    Dinic (int N) : N(N), G(N), dad(N), Q(N) {}

    void AddEdge (int from, int to, int cap) {
        G[from].pb(Edge(from, to, cap, 0, G[to].size()));
        if (from == to) G[from].back().index++;
        G[to].pb(Edge(to, from, 0, 0, G[from].size() - 1));
    }

    ll BlockingFlow (int s, int t) {
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

        ll totflow = 0;
        for (int i = 0; i < G[t].size(); i++) {
            Edge *start = &G[ G[t][i].to ][ G[t][i].index ];
            int amt = INF;
            for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
                if (!e) {
                    amt = 0;
                    break;
                }
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

    ll GetMaxFlow (int s, int t) {
        ll totFlow = 0;
        while (ll flow = BlockingFlow(s, t))
            totFlow += flow;
        return totFlow;
    }
};

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int n;
    while (cin >> n) {
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        Dinic din(2 * n + 2);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isPrime(a[i] + a[j])) {
//                    printf(">> %d %d\n", i, j);
//                    printf(">> %d %d\n", i + 1, n + j + 1);
                    din.AddEdge(i + 1, n + j + 1, 1);
//                    printf(">> %d %d\n", i, j);
                }
            }
        }

//        cout << "here" << endl;

        for (int i = 0; i < n; i++) {
            din.AddEdge(0, i + 1, 1);
            din.AddEdge(n + i + 1, n + n + 1, 1);
        }

        cout << din.GetMaxFlow(0, n + n + 1) / 2 << endl;
    }


    return 0;
}






