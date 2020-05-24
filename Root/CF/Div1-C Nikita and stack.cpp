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
int lazy[4 * SZ];
int mx[4 * SZ];

void propagate (int node) {
	lazy[2 * node] += lazy[node];
	lazy[2 * node + 1] += lazy[node];
	mx[2 * node] += lazy[node];
	mx[2 * node + 1] += lazy[node];
	lazy[node] = 0;
	return;
}

void update (int node, int b, int e, int l, int r, int x) {
	if (b >= l && e <= r) {
		mx[node] += x;
		lazy[node] += x;
	} else {
		propagate(node);
		int mid = (b + e) / 2;
		if (l <= mid) update(2 * node, b, mid, l, r, x);
		if (r > mid) update(2 * node + 1, mid + 1, e, l, r, x);
		mx[node] = max(mx[2 * node], mx[2 * node +1]);
	}
	return;
}

int query (int node, int b, int e) {
	if (mx[node] <= 0) return -1;
	if (b == e) return a[b];
	propagate(node);
	int mid = (b + e) / 2;
	if (mx[2 * node +1] > 0) return query(2 * node + 1, mid + 1, e);
	else return query(2 * node, b, mid);
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int p, x;
        cin >> p >> x;
        if (x == 1) {
            cin >> a[p];
			update(1, 1, m, 1, p, 1);
        } else {
			update(1, 1, m, 1, p, -1);
		}
		cout << query(1, 1, m) << endl;
    }

    return 0;
}





