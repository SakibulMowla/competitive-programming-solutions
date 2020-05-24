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
const int inf = 1E8;
const ll mod = 1E9;

#define SZ 100010

struct data {
    int x, y, z;
};

bool comp (data p, data q) {
    return p.x < q.x;
}

struct SegTree {
    int n;
    vector <int> tree;

    SegTree (int n): n(n), tree(4 * n + 10, inf) {
        ;
    }

    void update (int node, int b, int e, int pos, int val) {
        if (b == e) {
            tree[node] = val;
        } else {
            int mid = (b + e) >> 1;
            if (pos <= mid) update(2 * node, b, mid, pos, val);
            else update(2 * node + 1, mid + 1, e, pos, val);
            tree[node] = min(tree[2*node], tree[2*node+1]);
        }
        return;
    }

    int query (int node, int b, int e, int f, int t) {
        if (f > t) return inf;
        if (b >= f && e <= t) {
            return tree[node];
        } else {
            int mid = (b + e) >> 1, ret = inf;
            if (f <= mid) ret = query(2 * node, b, mid, f, t);
            if (t > mid) ret = min(ret, query(2 * node + 1, mid + 1, e, f, t));
            return ret;
        }
    }
};

struct Solve {
    int n;
    vector <data> a;

    Solve (int n): n(n), a(n) {
        for (auto &it: a) {
            cin >> it.x >> it.y >> it.z;
        }
        sort(a.begin(), a.end(), comp);
        process();
    }

    void process () {
        SegTree ST(n);
        int ans = 0;
        for (auto it: a) {
            int val = ST.query(1, 1, n, 1, it.y - 1);
            if (val > it.z) ans++;
            ST.update(1, 1, n, it.y, it.z);
        }
        cout << ans << endl;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        Solve Task(n);
    }


    return 0;
}




