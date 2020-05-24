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


#define SZ 500010

int cnt[SZ][26];
int oddCnt[SZ];
int col[SZ];
int sz[SZ];
bool big[SZ];
vector <int> g[SZ];
vector <pii> query[SZ];
bool ans[SZ];

void getsz(int v, int p){
    sz[v] = 1;
    for(auto u : g[v])
        if(u != p){
            getsz(u, v);
            sz[v] += sz[u];
        }
}

void add(int v, int p, int x, int lev) {
    if (cnt[lev][col[v]] & 1) {
        oddCnt[lev]--;
    } else {
        oddCnt[lev]++;
    }
    cnt[lev][ col[v] ] += x;

    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x, lev + 1);
}

void dfs(int v, int p, bool keep, int lev = 1) {
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

    for (auto &x: query[v]) {
        ans[x.second] = (oddCnt[x.first] <= 1);
    }

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1, lev);
}

char s[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif


    int n, q;
    scanf("%d %d", &n, &q);

    for (int i = 2; i <= n; i++) {
        int p;
        scanf("%d", &p);
        g[p].pb(i);
    }

    scanf("%s", s);

    for (int i = 1; i <= n; i++) {
        col[i] = s[i - 1] - 'a';
    }

    for (int i = 1; i <= q; i++) {
        int v, h;
        scanf("%d %d", &v, &h);
        query[v].pb({h, i});
    }

    getsz(1, 1);
    dfs(1, 1, 1);

    for (int i = 1; i <= q; i++) {
        if (ans[i]) puts("Yes");
        else puts("No");
    }

    return 0;
}





