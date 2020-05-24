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

	int n, a, b, k;
	cin >> n >> a >> b >> k;

	string s;
	cin >> s;

	vector <pii> v;
	int pos = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			int j = i;
			while (j + 1 < n && s[j + 1] == '0') j++;
			v.pb({i, j});
			pos += (j - i + 1) / b;
			i = j;
		}
	}

	// cout << ">> posb = " << pos << endl;

	vector <int> ans;

	for (int i = 0; i < v.size() && pos >= a; i++) {
		int strt = v[i].first, endd = v[i].second;
		while (endd - strt + 1 >= b && pos >= a) {
			pos--;
			ans.pb(strt + b - 1);
			strt += b;
		}
	}

	cout << ans.size() << endl;
	for (auto x: ans) {
		cout << x + 1 << ' ';
	}
	cout << endl;

    return 0;
}



