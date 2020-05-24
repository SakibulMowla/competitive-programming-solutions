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

vector < vector <int> > tree(4 * SZ, vector <int> ());

void merge (int node, int lft, int rht) {
	int l1 = tree[lft].size(), l2 = tree[rht].size();
	int p = 0, q = 0;
	while (p < l1 && q < l2) {
		if (tree[lft][p] < tree[rht][q]) tree[node].push_back(tree[lft][p]), p++;
		else tree[node].push_back(tree[rht][q]), q++;
	}
	while (p < l1) tree[node].push_back(tree[lft][p]), p++;
	while (q < l2) tree[node].push_back(tree[rht][q]), q++;
	return;
}

void build (int node, int b, int e, vector <int>& v) {
	if (b == e) {
		tree[node].push_back(v[b]);
	} else {
		int mid = (b + e) / 2;
		build(2 * node, b, mid, v);
		build(2 * node + 1, mid + 1, e, v);
		merge(node, 2 * node, 2 * node + 1);
	}
	return;
}

int query (int node, int b, int e, int f, int t) {
	if (b >= f && e <= t) {
		int lo = 0, hi = tree[node].size() - 1, ans = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (tree[node][mid] < f) {
				ans = mid;
				lo = mid + 1;
			} else hi = mid - 1;
		}
		return ans + 1;
	} else {
		int mid = (b + e) / 2, ans = 0;
		if (f <= mid) ans = query(2 * node, b, mid, f, t);
		if (t > mid) ans += query(2 * node + 1, mid + 1, e, f, t);
		return ans;
	}
}

int main() {

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < vector <int> > a(100010, vector <int> ());

    for (int i = 1; i <= n; i++) {
    	int x;
    	cin >> x;
    	a[x].push_back(i);
    }

    vector <int> b(n + 2);

    for (int i = 1; i <= 100000; i++) {
    	for (int j = 0; j < a[i].size(); j++) {
    		if (j < k) b[a[i][j]] = -1;
    		else b[a[i][j]] = a[i][j - k];
    	}
    }

    build(1, 1, n, b);

    int last = 0;
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
    	int x, y;
    	cin >> x >> y;
    	x = ((x + last) % n) + 1;
    	y = ((y + last) % n) + 1;
    	cout << (last = query(1, 1, n, min(x, y), max(x, y))) << endl;
    }

    return 0;
}




