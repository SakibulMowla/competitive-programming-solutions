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

int to[SZ];
int ans;
bool vis[SZ];

void dfs (int u) {
    vis[u] = 1;
    if (!to[u]) return;
    if (vis[to[u]]) {
        ans = -1;
        return;
    }
    ans++;
    dfs(to[u]);
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n, m, p;
    cin >> n >> m >> p;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (!to[b]) to[b] = a;
    }

    ans = 0;
    dfs(p);

    cout << ans << '\n';

    return 0;
}






