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
const ll inf = 1e17;
const ll mod = 1E9;

#define SZ 200010
#define SZ1 524288+100

ll h[SZ];
ll d[SZ];
ll sum[SZ];

struct data {
    ll lft, rht, ans;
};
data tree[SZ1];

data Merge (data a, data b) {
    data x;
    x.lft = max(a.lft, b.lft);
    x.rht = max(a.rht, b.rht);
    x.ans = max(a.lft + b.rht, max(a.ans, b.ans));
    return x;
}

void Build (int node, int l, int r) { /// Node, Left, Right
    if (l == r) {
        tree[node].lft = 2 * h[l] - sum[l];
        tree[node].rht = 2 * h[l] + sum[l];
        tree[node].ans = -inf;
    } else {
        int mid = (l + r) >> 1;
        Build(2 * node, l, mid);
        Build(2 * node + 1, mid + 1, r);
        tree[node] = Merge(tree[2 * node], tree[2 * node + 1]);
    }
    return;
}

data Query (int node, int l, int r, int f, int t) { /// Node, Left, Right, From, To
    if (l>=f && r<=t) {
        return tree[node];
    }
    int mid = (l + r) >> 1;
    data tmp;
    tmp.lft = tmp.rht = tmp.ans = -inf;
    if (f <= mid) tmp = Merge(tmp, Query(2 * node, l, mid, f, t));
    if (t > mid) tmp = Merge(tmp, Query(2 * node +1, mid + 1, r, f, t));
    return tmp;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &d[i]);
        d[i+n] = d[i];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &h[i]);
        h[i+n] = h[i];
    }

    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = sum[i-1] + d[i-1];
    }

    Build(1, 1, 2 * n);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a > b) {
            printf("%I64d\n", Query(1, 1, 2 * n, b + 1, a - 1).ans);
        } else {
            printf("%I64d\n", Query(1, 1, 2 * n, b + 1, a - 1 + n).ans);
        }
    }

    return 0;
}







