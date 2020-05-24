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

ll calc(ll n) {
	//cout << ">> " << n << endl;
	n = ((n + 5000 - 1) / 5000LL) * 5000LL - n;
	//cout << ">> " << n << endl;
	while (n >= 5000) n -= 5000;
	while (n >= 1000) n -= 1000;
	while (n >= 500) n -= 500;
	ll ans = 0;
	while (n >= 100) n -= 100, ans += 100;
	while (n >= 50) n -= 50, ans += 50;
	while (n >= 10) n -= 10, ans += 10;
	while (n >= 5) n -= 5, ans += 5;
	while (n >= 1) n -= 1, ans += 1;
	return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    ll n, a;
    cin >> n >> a;

    ll ans = 0;
    for (int i = 0; i < 6000; i++) {
    	ll a1 = a + i;
    	ll a2 = n - a1;
    	if (a2 < a) break;
    	ans = max(ans, calc(a1) + calc(a2));
    }

    cout << ans << endl;

    return 0;
}




