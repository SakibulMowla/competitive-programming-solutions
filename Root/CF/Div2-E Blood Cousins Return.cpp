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

map <pii, int> cnt;
int col[SZ];
int sz[SZ];
int bc[SZ];
bool big[SZ];
vector <int> g[SZ];
vector <pii> query[SZ];
int ans[SZ];
int uniqueNodes[SZ];

void getsz(int v, int p){
    sz[v] = 1;
    bc[v] = -1;
    int mx = -1;
    for(auto u : g[v])
        if(u != p) {
            getsz(u, v);
            sz[v] += sz[u];
            if (sz[u] > mx) {
                mx = sz[u];
                bc[v] = u;
            }
        }
}

void add(int v, int p, int x, int lev) {
    if (x == 1 && (cnt.find({lev, col[v]}) == cnt.end() || cnt[{lev, col[v]}] == 0)) {
        uniqueNodes[lev]++;
    }
    if (x == -1 && cnt[{lev, col[v]}] == 1) {
        uniqueNodes[lev]--;
    }
    if (cnt.find({lev, col[v]}) == cnt.end()) {
        cnt[{lev, col[v]}] = x;
    } else {
        cnt[{lev, col[v]}] += x;
    }

    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x, lev + 1);
}

void dfs(int v, int p, bool keep, int lev) {
    int bigChild = bc[v];
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0, lev + 1);
    if(bigChild != -1)
        dfs(bigChild, v, 1, lev + 1), big[bigChild] = 1;
    add(v, p, 1, lev);

    for (auto &x: query[v]) {
        ans[x.second] = (x.first+lev) < SZ? uniqueNodes[x.first+lev]: 0;
    }

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1, lev);
}

unordered_map <string, int> mp;

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    vector <int> root;
    cin >> n;

    for (int i = 1, cnt = 0; i <= n; i++) {
        string s;
        int p;
        cin >> s >> p;

        if (mp.find(s) == mp.end()) {
            col[i] = mp[s] = ++cnt;
        } else {
            col[i] = mp[s];
        }

        if (p) g[p].pb(i);
        else root.pb(i);
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        query[v].pb({k, i});
    }

    for (auto &x: root) {
        getsz(x, x);
        dfs(x, x, 1, 1);
        cnt.clear();
        memset(uniqueNodes, 0, sizeof uniqueNodes);
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}





