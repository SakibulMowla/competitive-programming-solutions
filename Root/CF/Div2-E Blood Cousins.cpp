#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

int cnt[SZ];
int sz[SZ];
bool big[SZ];
int ans[SZ];
vector <int> g[SZ];
vector <pii> query[SZ];


void getsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}

void add(int v, int p, int x, int lev) {
    cnt[lev] += x;
    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x, lev + 1);
}

void dfs(int v, int p, bool keep, int lev) {
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
        if(u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0, lev + 1);
    if(bigChild != -1)
        dfs(bigChild, v, 1, lev + 1), big[bigChild] = 1;
    add(v, p, 1, lev);

    for (auto x: query[v]) {
        ans[x.second] = cnt[x.first + lev] - 1;
    }

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1, lev);
}

int P[SZ][20];

void LCAdfs (int v, int p) {
//    cout << ">> " << v << ' ' << p << endl;
    for (auto u: g[v])
        if (u != p) {
            P[u][0] = v;
            LCAdfs(u, v);
        }
    return;
}

void preProcess (int n) {
    for (int j = 1; j < 17; j++) {
        for (int i = 1; i <= n; i++) {
            if (P[i][j-1] != -1) {
                P[i][j] = P[P[i][j-1]][j-1];
            }
        }
    }
}

int find (int v, int p) {
    for (int i = 16; i >= 0; i--) {
        if (p & (1 << i)) {
            v = P[v][i];
//            cout << ">>> " << i << ' ' << v << endl;
            if (v == -1) break;
        }
    }
    return v;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    vector <int> root;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p) g[p].pb(i);
        else root.pb(i);
    }

    memset(P, -1, sizeof P);

    for (auto x: root) {
        LCAdfs(x, x);
    }

    preProcess(n);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, p;
        cin >> v >> p;
        v = find(v, p);
        if (v != -1) query[v].pb({p, i});
        else ans[i] = 0;
    }

    for (auto x: root) {
        getsz(x, x);
        dfs(x, x, 1, 1);
        memset(cnt, 0, sizeof cnt);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}




