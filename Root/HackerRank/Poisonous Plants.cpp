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

int mark[SZ];
int tree[4*SZ];

bool comp (pii a, pii b) {
    if (a.X == b.X) {
        return a.Y < b.Y;
    }
    return a.X > b.X;
}

int query (int node, int b, int e, int f, int t) {
    if (f > t) {
        return 0;
    }
    else if (b >= f && e <= t) {
        return tree[node];
    } else {
        int mid = (b + e) >> 1;
        int ret = 0;
        if (f <= mid) ret = query(2 * node, b, mid, f, t);
        if (t > mid) ret = max(ret, query(2 * node + 1, mid + 1, e, f, t));
        return ret;
    }
}

void update (int node, int b, int e, int pos, int v) {
    if (b == e) {
        tree[node] = v;
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos, v);
        else update(2 * node + 1, mid + 1, e, pos, v);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("3.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector <int> a(n);
        vector <pii> val;
        set <int> ms;
        int pre = 2E9;
        mem(mark, 0);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] <= pre) {
                pre = a[i];
                mark[i] = 1;
            }
            val.pb({a[i], i});
            ms.insert(i);
        }

        sort(val.begin(), val.end(), comp);
        mem(tree, 0);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!mark[val[i].Y]) {
                ms.erase(val[i].Y);
                int to = *prev(ms.lower_bound(val[i].Y));
                int tmp = query(1, 0, n - 1, to, val[i].Y) + 1;
                update(1, 0, n - 1, val[i].Y, tmp);
                ans = max(ans, tmp);
            }
        }

        cout << ans << endl;
    }



    return 0;
}



