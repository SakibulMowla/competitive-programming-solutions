#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 500010

int tree[4*SZ];
int pre[SZ];

void Build (int node, int b, int e) {
    tree[node] = 1E6;
    if (b == e) return;
    int mid = (b + e) >> 1;
    Build(node<<1, b, mid);
    Build(node<<1|1, mid+1, e);
}

void Update (int node, int b, int e, int x, int val) {
    if (b == e) {
        tree[node] = val;
        return;
    }

    int mid = (b + e) >> 1;

    if (x <= mid) Update(node<<1, b, mid, x, val);
    else Update(node<<1|1, mid+1, e, x, val);

    tree[node] = min(tree[node<<1], tree[node<<1|1]);
}

int Query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) return tree[node];

    int mid = (b + e) >> 1, ret = 1E6;

    if (f <= mid) ret = min(ret, Query(node<<1, b, mid, f, t));
    if (t > mid) ret = min(ret, Query(node<<1|1, mid+1, e, f, t));

    return ret;
}

map <int , int> mp;
vector <pii> v[SZ];
int ans[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (mp.find(x) == mp.end()) pre[i] = -1;
        else pre[i] = mp[x];
        mp[x] = i;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].pb({a, i});
    }

    Build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        if (pre[i] != -1) Update(1, 1, n, pre[i], i - pre[i]);
        for (int j = 0; j < sz(v[i]); j++) {
            ans[ v[i][j].Y ] = Query(1, 1, n, v[i][j].X, i);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << (ans[i] == 1E6 ? -1 : ans[i]) << '\n';
    }

    return 0;
}







