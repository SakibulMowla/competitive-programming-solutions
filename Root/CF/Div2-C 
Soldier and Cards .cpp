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

deque <int> a, b;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;
	
	int k1;	
	cin >> k1;
	for (int i = 0; i < k1; i++) {
		int x;
		cin >> x;
		a.push_back(x);
	}
	
	int k2;
	cin >> k2;
	for (int i = 0; i < k2; i++) {
		int x;
		cin >> x;
		b.push_back(x);
	}
	
	for (int i = 0; i < 123456; i++) {
		if (sz(a) == 0) {
			cout << i << ' ' << 2 << endl;
			return 0;
		}
		else if (sz(b) == 0) {
			cout << i << ' ' << 1 << endl;
			return 0;
		}
		
		if (a.front() > b.front()) {
			a.push_back(b.front());
			a.push_back(a.front());
		} 
		else {
			b.push_back(a.front());
			b.push_back(b.front());
		}
		a.pop_front();
		b.pop_front();
	}
	
	cout << -1 << endl;


    return 0;
}






