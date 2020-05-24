#include <bits/stdc++.h>

using namespace  std;

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010
#define SZ1 4*SZ

int a[SZ];
int tree[SZ1];

void build(int node, int b, int e) {
    if (b == e) {
        tree[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(2 * node, b, mid);
    build(2 * node + 1, mid + 1, e);
    tree[node] = __gcd(tree[2 * node], tree[2 * node + 1]);
    return;
}

int query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return tree[node];
    }
    int mid = (b + e) >> 1, ans = 0;
    if (f <= mid) ans = query(2 * node, b, mid, f, t);
    if (t > mid) ans = __gcd(ans, query(2 * node + 1, mid + 1, e, f, t));
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        build(1, 1, n);

        while (q--) {
            int l, r;
            cin >> l >> r;
            int ans = 0;
            if (l != 1) ans = query(1, 1, n, 1, l - 1);
            if (r != n) ans = __gcd(ans, query(1, 1, n, r + 1, n));
            cout << ans << '\n';
        }
    }

    return 0;
}




