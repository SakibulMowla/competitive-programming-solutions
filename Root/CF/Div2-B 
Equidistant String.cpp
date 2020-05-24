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

#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
	
	FAST
	
	string s, t;
	cin >> s >> t;
	
	int len = sz(s);
	int cnt = 0;
	
	for (int i = 0; i < len; i++) {
		if (s[i] != t[i]) {
			cnt++;
		}
	}
	
	if (cnt & 1) {
		cout << "impossible" << endl;
	} else {
		int cnt1 = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] != t[i]) {
				if (cnt1 < cnt / 2) cout << s[i];
				else cout << t[i];
				cnt1++;
			} else {
				cout << s[i];
			}
		}
		cout << endl;
	}

    return 0;
}






