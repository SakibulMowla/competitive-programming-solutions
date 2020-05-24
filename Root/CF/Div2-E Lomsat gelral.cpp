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
int col[SZ];
int sz[SZ];
bool big[SZ];
vector <int> g[SZ];
ll sum[SZ];
ll ans[SZ];
set <int> ms;

void getsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}

void add(int v, int p, int x) {
    if ((x == 1 && cnt[col[v]]) || x == -1) {
        ms.erase(cnt[col[v]]);
        sum[cnt[col[v]]] -= (ll)col[v];
    }
    cnt[ col[v] ] += x;
    if (x == 1 || (x == -1 && cnt[col[v]])) {
        ms.insert(cnt[col[v]]);
        sum[cnt[col[v]]] += (ll)col[v];
    }

    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}

void dfs(int v, int p, bool keep) {
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
        if(u != p && sz[u] > mx)
            mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;
    add(v, p, 1);

    ans[v] = sum[*prev(ms.end())];

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }

    getsz(1, 1);
    dfs(1, 1, 1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}





