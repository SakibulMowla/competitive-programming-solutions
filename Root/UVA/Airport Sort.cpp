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

#define SZ 20010
#define SZ1 4*20010

int tree[SZ1];

void update (int node, int b, int e, int pos) {
    if (b == e) {
        tree[node] = 1;
    } else {
        int mid = (b + e) >> 1;
        if (pos <= mid) update(2 * node, b, mid, pos);
        else update(2 * node + 1, mid + 1, e, pos);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    return;
}

int query (int node, int b, int e, int f, int t) {
    if (f > t) return 0;
    if (b >= f && e <= t) {
        return tree[node];
    } else {
        int mid = (b + e) >> 1;
        int ret = 0;
        if (f <= mid) ret = query(2 * node, b, mid, f, t);
        if (t > mid) ret += query(2 * node + 1, mid + 1, e, f, t);
        return ret;
    }
}

vector <int> pos[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> n >> k;

        for (int i = 0; i <= n / k; i++) {
            clr(pos[i]);
        }

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            --x;
            pos[x/k].pb(i);
        }

        int a = 0;

        for (int i = 0; i <= n/ k; i++) {
            for (int j = 0; j < sz(pos[i]); j++) {
                a = max(a, abs(i * k + j - pos[i][j]));
            }
        }

        int b = 0;
        mem(tree, 0);

        for (int i = 0; i <= n / k; i++) {
            for (int j = 0; j < sz(pos[i]); j++) {
                b += query(1, 0, n - 1, pos[i][j] + 1, n - 1);
            }
            for (int j = 0; j < sz(pos[i]); j++) {
                update(1, 0, n - 1, pos[i][j]);
            }
        }

        cout << "Case " << cs + 1 << ": " << b - a << endl;
    }


    return 0;
}







