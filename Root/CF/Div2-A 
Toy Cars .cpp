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
using VI = vector < int >;
using VVI = vector < VI >;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	int n;
	cin >> n;
	
	VI cnt(n, 0);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				cnt[i]++;
			} else if (x == 2) {
				cnt[j]++;
			} else if (x == 3) {
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	
	VI ans;
	for (int i = 0; i < n; i++) {
		if (cnt[i] == 0) {
			ans.pb(i + 1);
		}
	}	
	
	cout << sz(ans) << endl;
	for (int i = 0; i < sz(ans); i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;

    return 0;
}






