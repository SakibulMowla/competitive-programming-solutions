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

#define SZ 1010

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	ios_base::sync_with_stdio(0);	
	
	int n;
	cin >> n;

	vector <int> a(n);
	vector <int> used(n + n + 1, 0);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	sort(a.begin(), a.end());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int now = a[i];
		while (used[now] != 0) {
			ans++;
			now++;
		}
		used[now] = 1;
	}
	
	cout << ans << endl;

    return 0;
}






