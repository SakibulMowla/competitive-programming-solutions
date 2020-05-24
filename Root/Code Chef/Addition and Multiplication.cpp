#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1E9+7;

#define SZ  100010

struct data {
    ll add, mul, sum;
};

data tree[4*SZ];
ll a[SZ];

void new_sum (int node) {
    tree[node].sum = tree[2*node].sum + tree[2*node+1].sum;
    if (tree[node].sum >= mod) {
        tree[node].sum -= mod;
    }
}

void build (int node, int b, int e) {
    if (b == e) {
        tree[node].add = 0;
        tree[node].mul = 1;
        tree[node].sum = a[b];
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        new_sum(node);
    }
    return;
}

void propagate (int &node, int &b, int &e, int &mid) {
    tree[2 * node].sum = (tree[2 * node].sum * tree[node].mul) % mod;
    tree[2 * node + 1].sum = (tree[2 * node + 1].sum * tree[node].mul) % mod;

    tree[2 * node].mul = (tree[2 * node].mul * tree[node].mul) % mod;
    tree[2 * node + 1].mul = (tree[2 * node + 1].mul * tree[node].mul) % mod;
    tree[node].mul = 1;

    tree[2 * node].sum += (tree[node].add * (mid - b + 1LL)) % mod;
    if (tree[2 * node].sum >= mod) tree[2 * node].sum -= mod;
    tree[2 * node + 1].sum += (tree[node].add * (e - mid)) % mod;
    if (tree[2 * node + 1].sum >= mod) tree[2 * node + 1].sum -= mod;

    tree[2 * node].add += tree[node].add;
    if (tree[2 * node].add >= mod) tree[2 * node].add -= mod;
    tree[2 * node + 1].add += tree[node].add;
    if (tree[2 * node + 1].add >= mod) tree[2 * node + 1].add -= mod;
    tree[node].add = 0;

    return;
}

void update_add_v (int node, int b, int e, int f, int t, ll v) {
    if (b >= f && e <= t) {
        tree[node].sum += (v * (e - b + 1LL)) % mod;
        if (tree[node].sum >= mod) {
            tree[node].sum -= mod;
        }
        tree[node].add = tree[node].add + v;
        if (tree[node].add >= mod) {
            tree[node].add -= mod;
        }
    } else {
        int mid = (b + e) >> 1;
        propagate(node, b, e, mid);
        if (f <= mid) update_add_v(2 * node, b, mid, f, t, v);
        if (t > mid) update_add_v(2 * node + 1, mid + 1, e, f, t, v);
        new_sum(node);
    }
    return;
}

void update_mul_v (int node, int b, int e, int f, int t, ll v) {
    if (b >= f && e <= t) {
        tree[node].sum = (tree[node].sum * v) % mod;
        tree[node].mul = (tree[node].mul * v) % mod;
        tree[node].add = (tree[node].add * v) % mod;
    } else {
        int mid = (b + e) >> 1;
        propagate(node, b, e, mid);
        if (f <= mid) update_mul_v(2 * node, b, mid, f, t, v);
        if (t > mid) update_mul_v(2 * node + 1, mid + 1, e, f, t, v);
        new_sum(node);
    }
    return;
}

ll query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return tree[node].sum;
    } else {
        int mid = (b + e) >> 1;
        propagate(node, b, e, mid);
        ll ret = 0;
        if (f <= mid) ret = query(2 * node, b, mid, f, t);
        if (t > mid) ret = (ret + query(2 * node + 1, mid + 1, e, f, t)) % mod;
        new_sum(node);
        return ret;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            update_add_v(1, 1, n, x, y, v);
        } else if (k == 2) {
            int x, y, v;
            cin >> x >> y >> v;
            update_mul_v(1, 1, n, x, y, v);
        } else if (k == 3) {
            int x, y, v;
            cin >> x >> y >> v;
            update_mul_v(1, 1, n, x, y, 0);
            update_add_v(1, 1, n, x, y, v);
        } else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << endl;
        }
    }

    return 0;
}





