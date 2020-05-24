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
const ll mod = 1LL;

#define SZ  500010

int tree[4*SZ];
int a[SZ];

int GCD (int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
}

void build (int node, int b, int e) {
    if (b == e) {
        tree[node] = a[b];
    } else {
        int mid = (b + e) >> 1;
        build(2 * node, b, mid);
        build(2 * node + 1, mid + 1, e);
        tree[node] = GCD(tree[2 * node], tree[2 * node + 1]);
    }
    return;
}

int query (int node, int b, int e, int f, int t) {
    if (b >= f && e <= t) {
        return tree[node];
    } else {
        int ans = 0, mid = (b + e) >> 1;
        if (f <= mid) ans = query(2 * node, b, mid, f, t);
        if (t > mid) ans = GCD(ans, query(2 * node + 1, mid + 1, e, f, t));
        return ans;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n - 1);

    int ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
        j = max(j, i);
        int now = query(1, 0, n - 1, i, j);
        if (now >= k) {
            ans = max(ans, j - i + 1);
            while (j + 1 < n && GCD(now, a[j + 1]) >= k) {
                now = GCD(now, a[j + 1]);
                j++;
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << endl;

    return 0;
}




