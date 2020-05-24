#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

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
	cin >> n;

	string s, ans = "";
	cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'o') {
			int j = i + 1;
			while (j + 1 < n && s[j] == 'g' && s[j + 1] == 'o') {
				j += 2;
			}
			if (j != i + 1) {
				ans += "***";
				i = j - 1;
			} else {
				ans += s[i];
			}
		} else {
			ans += s[i];
		}
	}

	cout << ans << endl;

    return 0;
}






