#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>

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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios::sync_with_stdio(false);

	int n, s, extra = 0, zeroes = 0;
	cin >> n >> s;

	vector <int> cnt(n + 2, 0), absent(n + 2, 1);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == s - 1 && x != 0) {
			x = 0;
			extra = 1;
		}
		cnt[x]++;
		absent[x] = 0;
		zeroes += (x == 0);
	}

	for (int i = 1; i <= n; i++) {
		absent[i] += absent[i-1];
	}

	for (int i = n; i >= 0; i--) {
		cnt[i] += cnt[i+1];
	}

	int ans = cnt[2] + zeroes - 1;
	for (int i = 2; i < n; i++) {
		ans = min(ans, max(absent[i], cnt[i+1] + zeroes - 1));
	}

	cout << ans + extra << endl;

    return 0;
}
