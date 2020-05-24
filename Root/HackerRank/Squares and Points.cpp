#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

int x[3*SZ];
int y[3*SZ];
int xcnt;
int ycnt;

int lazy[12*SZ];

void propagate (int node) {
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
    return;
}

void update (int node, int b, int e, int f, int t, int val) {
    if (b >= f && e <= t) {
        lazy[node] += val;
    } else {
        if (lazy[node]) propagate(node);
        int mid = (b + e) >> 1;
        if (f <= mid) update(2 * node, b, mid, f, t, val);
        if (t > mid) update(2 * node + 1, mid + 1, e, f, t, val);
    }
    return;
}

int query (int node, int b, int e, int pos) {
    if (b == e) {
        return lazy[node];
    } else {
        if (lazy[node]) propagate(node);
        int mid = (b + e) >> 1, ans;
        if (pos <= mid) ans = query(2 * node, b, mid, pos);
        else ans = query(2 * node + 1, mid + 1, e, pos);
        return ans;
    }
}

vector <pii> ins[3*SZ], del[3*SZ];
vector <int> qry[3*SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m, l;
    cin >> n >> m >> l;

    vector <pii> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].X >> v[i].Y;
        x[xcnt++] = v[i].X;
        x[xcnt++] = v[i].X + l + 1;
        y[ycnt++] = v[i].Y;
        y[ycnt++] = v[i].Y + l;
    }

    vector <pii> q(m);

    for (int i = 0; i < m; i++) {
        cin >> q[i].X >> q[i].Y;
        x[xcnt++] = q[i].X;
        y[ycnt++] = q[i].Y;
    }

    sort(x, x + xcnt);
    sort(y, y + ycnt);

    xcnt = unique(x, x + xcnt) - x;
    ycnt = unique(y, y + ycnt) - y;

    for (int i = 0; i < n; i++) {
        ins[lower_bound(x, x + xcnt, v[i].X) - x].pb({lower_bound(y, y + ycnt, v[i].Y) - y, lower_bound(y, y + ycnt, v[i].Y + l) - y});
        del[lower_bound(x, x + xcnt, v[i].X + l + 1) - x].pb({lower_bound(y, y + ycnt, v[i].Y) - y, lower_bound(y, y + ycnt, v[i].Y + l) - y});
    }

    for (int i = 0; i < m; i++) {
        qry[lower_bound(x, x + xcnt, q[i].X) - x].pb(lower_bound(y, y + ycnt, q[i].Y) - y);
    }

    int ans = 0;
    for (int i = 0; i < xcnt; i++) {
        for (int j = 0; j < sz(ins[i]); j++) {
            update(1, 0, ycnt - 1, ins[i][j].X, ins[i][j].Y, 1);
        }
        for (int j = 0; j < sz(del[i]); j++) {
            update(1, 0, ycnt - 1, del[i][j].X, del[i][j].Y, -1);
        }
        for (int j = 0; j < sz(qry[i]); j++) {
            ans = max(ans, query(1, 0, ycnt - 1, qry[i][j]));
        }
    }

    cout << ans << endl;

    return 0;
}


