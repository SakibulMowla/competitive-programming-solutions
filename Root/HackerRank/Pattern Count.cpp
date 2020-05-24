#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    for (int cs = 0; cs < q; cs++) {
    	string s;
    	cin >> s;
    	int n = sz(s);

    	int ans = 0;
    	for (int i = 0; i < n - 1; i++) {
    		if (s[i] == '1' && s[i + 1] == '0') {
    			int j = i + 1;
    			while (j + 1 < n && s[j + 1] == '0') j++;
    			if (j + 1 < n && s[j + 1] == '1') ans++;
    			i = j;
    		}
    	}

    	cout << ans << endl;
    }

    return 0;
}


