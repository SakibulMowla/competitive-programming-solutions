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

	int n;
	string s;

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		for (int k = 1; i + 4 * k < n; k++) {
			if (s[i+0*k] == '*' && s[i+1*k] == '*' && s[i+2*k] == '*' && s[i+3*k] == '*' && s[i+4*k] == '*') {
				cout << "yes" << '\n';
				return 0;
			}			
		}		
	}
	cout << "no" << '\n';

    return 0;
}






