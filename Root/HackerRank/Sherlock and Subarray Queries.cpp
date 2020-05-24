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

#define SZ 100010

int x[4*SZ];
int y[4*SZ];
int a[SZ];

void build (int node, int b, int e) {
//    cout << node << ' ' << b << ' ' << e << endl;
    if (b == e) {
        x[node] = a[b];
        y[node] = 1;
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        if (x[2 * node] == x[2 * node + 1]) {
            x[node] = x[2 * node];
            y[node] = y[2 * node] + y[2 * node + 1];
        } else {
            if (x[2 * node] > x[2 * node + 1]) {
                x[node] = x[2 * node];
                y[node] = y[2 * node];
            } else {
                x[node] = x[2 * node + 1];
                y[node] = y[2 * node + 1];
            }
        }
    }
    return;
}

pii query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return {x[node], y[node]};
    }
    int mid = (b + e) >> 1;
    pii a = {0, 0};
    pii bb = {0, 0};
    if (f <= mid) a = query(2 * node, b, mid, f, t);
    if (t > mid) bb = query(2 * node + 1, mid + 1, e, f, t);
    if (a.X == bb.X) {
        a.Y += bb.Y;
    } else {
        if (a.X < bb.X) {
            swap(a, bb);
        }
    }
    return a;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    for (int i = 0; i < m; i++) {
        int p, q;
        cin >> p >> q;
        cout << query(1, 1, n, p, q).Y << endl;
    }


    return 0;
}







