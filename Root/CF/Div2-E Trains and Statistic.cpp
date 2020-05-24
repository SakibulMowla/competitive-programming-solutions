#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

int a[SZ];
ll cost[SZ];
int tree[4*SZ];
int max_val[4*SZ];

void update (int node, int b, int e, int x) {
    if (b == e) {
        tree[node] = x;
        max_val[node] = a[x];
    } else {
        int mid = (b + e) / 2;
        if (x <= mid) update(2 * node, b, mid, x);
        else update(2 * node + 1, mid + 1, e, x);
        if (max_val[2 * node] > max_val[2 * node + 1]) max_val[node] = max_val[2 * node], tree[node] = tree[2 * node];
        else max_val[node] = max_val[2 * node + 1], tree[node] = tree[2 * node + 1];
    }
    return;
}

pii query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return {max_val[node], tree[node]};
    } else {
        int mid = (b + e) / 2;
        pii ans, ans1 = {-1, -1}, ans2 = {-1, -1};
        if (f <= mid) ans1 = query(2 * node, b, mid, f, t);
        if (t > mid) ans2 = query(2 * node + 1, mid + 1, e, f, t);
        if (ans1.X > ans2.X) ans = ans1;
        else ans = ans2;
        return ans;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] == n) {
            cost[i] = (ll)(n - i);
        } else {
            cost[i] = (ll)(a[i] - i);
            pii aa = query(1, 1, n, i + 1, a[i]);
            int node = aa.Y;
//            cout << "node val " << node << ' ' << aa.X << ' ' << i + 1 << ' ' << a[i] << endl;
            ll tmp = cost[node] - (a[i] - node) + (n - a[i]);
            cost[i] += tmp;
        }
        ans += cost[i];
        update(1, 1, n, i);
//        cout << ans << ' ' << cost[i] << endl;
    }

    cout << ans << endl;

    return 0;
}


