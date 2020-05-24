#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010



int main() {
//#if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("23.txt", "w", stdout);
//#endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
    	vector <ll> a(n + 2, 0), prefix_xor(n + 2, 0);
    	for (int i = 1; i <= n; i++) {
    		cin >> a[i];
    		prefix_xor[i] = a[i] ^ prefix_xor[i - 1];
    	}

    	ll ans = 0, xor_sum = 0;
    	for (int i = n + 1; i >= 1; i--) {
    		xor_sum ^= a[i];
    		for (int j = i - 1; j >= 0; j--) {
    			ans = max(ans, prefix_xor[j] ^ xor_sum);
    		}
    	}

    	cout << ans << endl;
    }

    return 0;
}




