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

#define SZ 200010

struct data {
    int a, b, c;
    data () {}
    data (int u, int v, int w) {
        a = u, b = v, c = w;
    }
};

bool comp (data p, data q) {
    return p.c < q.c;
}

int par[SZ];
vector <data> adj[SZ];

int Find (int r) {
    if (r == par[r]) return r;
    return par[r] = Find(par[r]);
}

void MST (int n, int m, vector <data>& edge) {
    sort(edge.begin(), edge.end(), comp);
    for (int i = 0; i <= n; i++) {
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int x = Find(edge[i].a);
        int y = Find(edge[i].b);
        if (x != y) {
            par[x] = y;
            adj[edge[i].a].pb(data(edge[i].b, edge[i].c, 0));
            adj[edge[i].b].pb(data(edge[i].a, edge[i].c, 0));
        }
    }
    return;
}

ll bits[20000000];
ll cnt[SZ];

void dfs (int u, int p) {
    cnt[u] = 1;
    for (auto v: adj[u]) {
        if (v.a != p) {
            dfs(v.a, u);
            cnt[u] += cnt[v.a];
        }
    }
    return;
}

void solve (int u, int p, int n) {
    for (auto v: adj[u]) {
        if (v.a != p) {
            bits[v.b] += cnt[v.a] * (n - cnt[v.a]);
            solve(v.a, u, n);
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

    int n, m;
    cin >> n >> m;

    vector <data> edge;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.pb(data(a, b, c));
    }

    MST(n, m, edge);
    dfs(1, 1);
    solve(1, 1, n);

    for (int i = 0; i <= 12000000; i++) {
        bits[i + 1] += bits[i] / 2;
        bits[i] = (bits[i] & 1LL);
    }

    bool start = false;
    for (int i = 12000000; i >= 0; i--) {
        if (start) cout << bits[i];
        else {
            if (bits[i]) {
                start = true;
                cout << bits[i];
            }
        }
    }
    if (!start) cout << 0;
    cout << endl;

    return 0;
}



