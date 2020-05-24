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
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, c, k;
    cin >> n >> c >> k;

    vector <int> a(n);
    for (auto &x: a) cin >> x;
    sort(a.begin(), a.end());

    int last = -1, cap = 0, cnt = 0;
    for (auto &x: a) {
    	if (last < x || 0 == cap) {
    		cnt++;
    		last = x + k;
    		cap = c - 1;
    	} else {
    		cap--;
    	}
    }

    cout << cnt << endl;

    return 0;
}





