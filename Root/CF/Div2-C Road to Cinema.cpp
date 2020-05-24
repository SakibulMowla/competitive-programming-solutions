#include <iostream>
#include <algorithm>
#include <vector>

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

ll needed (vector <int>& gas, ll cap) {
	ll tym = 0;
	for (int i = 1; i < gas.size(); i++) {
		// cout << ">>> " << gas[i] << ", " << gas[i-1] << endl;
		if (gas[i] != gas[i-1]) {
			ll dist = gas[i] - gas[i-1];
			if (dist > cap) return 3E9;
			ll dist1 = min(dist, cap - dist);
			ll dist2 = dist - dist1;
			tym += dist1 + 2LL * dist2;
		}
	}
	return tym;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios::sync_with_stdio(false);

	ll n, k, s, t;
	cin >> n >> k >> s >> t;

	vector <pll> car(n);
	for (auto &x: car) {
		cin >> x.X >> x.Y;
	}

	vector <int> gas(k);
	for (auto &x: gas) {
		cin >> x;
	}

	gas.push_back(0);
	gas.push_back(s);

	sort(gas.begin(), gas.end());

	ll lo = 1, hi = 1E9, ans = 3E9;
	while (lo <= hi) {
		ll mid = (lo + hi) / 2;
		if (needed(gas, mid) <= t) {
			ans = mid;
			hi = mid - 1;
		} else {
			lo = mid + 1;
		}
	}

	// cout << ">> " << ans << endl;

	ll min_cost = 3E9;
	for (auto x: car) {
		if (x.Y >= ans) {
			min_cost = min(min_cost, x.X);
		}
	} 

	cout << (min_cost == 3E9? -1: min_cost) << endl;

    return 0;
}






