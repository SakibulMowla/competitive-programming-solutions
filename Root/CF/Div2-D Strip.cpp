#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

ll a[SZ];
ll mx[4*SZ], mn[4*SZ];

void build (int node, int b, int e) {
    if (b == e) {
        mx[node] = mn[node] = a[b];
        return;
    }
    int mid = (b + e) >> 1;
    build(2*node, b, mid);
    build(2*node+1, mid+1, e);
    mx[node] = max(mx[2*node], mx[2*node+1]);
    mn[node] = min(mn[2*node], mn[2*node+1]);
    return;
}

ll querymx (int node, int b, int e, int f, int t) {
    if (b>=f && e<=t) return mx[node];
    int mid = (b + e) >> 1;
    ll ret = -1e17;
    if (f <= mid) ret = querymx(2*node, b, mid, f, t);
    if (t > mid) ret = max(ret, querymx(2*node+1, mid+1, e, f, t));
    return ret;
}

ll querymn (int node, int b, int e, int f, int t) {
    if (b>=f && e<=t) return mn[node];
    int mid = (b + e) >> 1;
    ll ret = 1e17;
    if (f <= mid) ret = querymn(2*node, b, mid, f, t);
    if (t > mid) ret = min(ret, querymn(2*node+1, mid+1, e, f, t));
    return ret;
}

int nxt[SZ];
vector <int> v;
int tree[SZ];

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n) {
    while(idx <= n+1) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int bs (int now) {
    int lo = 0;
    int hi = sz(v)-1;
    int ans;

    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (v[mid] <= nxt[now]) {
            ans = v[mid];
            lo = mid + 1;
        } else hi = mid - 1;
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n, l;
    ll s;
    while(cin >> n >> s >> l) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        build(1, 1, n);

        int j = 1;
        for (int i = 1; i <= n; i++) {
            for (; j <= n; j++) {
                if (querymx(1, 1, n, i, j) - querymn(1, 1, n, i, j) > s) break;
            }
            if (j-i >= l) nxt[i] = j;
            else nxt[i] = -1;
//            printf("i = %d j = %d\n", i, j);
        }

        clr(v);
        mem(tree, 0);
        v.pb(n+1);
        update(n+1, 1, n);

        for (int i = n; i >= 1; i--) if (nxt[i] != -1) {
            int from = i + l, to = nxt[i];
            if (query(to) - query(from-1) > 0) {
                update(i, 1, n);
                v.pb(i);
            }
        }

        sort(v.begin(), v.end());

        if (v[0] != 1) {
            cout << "-1\n";
            continue;
        }

        int now = 1, ans = 0;
        while (1) {
            ans++;
            now = bs(now);
            if (now == n+1) break;
        }

        cout << ans << '\n';
    }

    return 0;
}


/*
7 2 2
1 3 1 2 4 1 2
*/



