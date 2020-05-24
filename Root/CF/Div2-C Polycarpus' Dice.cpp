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

#define SZ 200010

ll d[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

	ll n, s;
	
	while (scanf("%I64d %I64d", &n, &s) == 2) {
		ll x = 0;
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &d[i]);
			x += d[i];
		}
		
		for (int i = 0; i < n; i++) {
			ll hi = s - n + 1LL;
			ll lo = s - x + d[i];
			if (hi > d[i]) hi = d[i];
			if (lo < 1) lo = 1;
			printf("%I64d ", lo - 1LL + d[i] - hi);
		} 
		printf("\n");
	}


    return 0;
}






