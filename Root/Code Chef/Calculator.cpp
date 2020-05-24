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

    //ios::sync_with_stdio(false);

    int t;
    //cin >> t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll n, b;
        //cin >> n >> b;
        scanf("%lld %lld", &n, &b);

        ll lo = 0, hi = 2E9, ans = 0;
        while (lo <= hi) {
        	ll mid = lo + (hi - lo) / 2;
        	ll mid1 = mid + 1;
        	
        	ll one = n * mid - b * mid * mid;
        	ll two = n * mid1 - b * mid1 * mid1;
        	
        	if (one > two) {
        		hi = mid - 1;
        		ans = max(ans, one);
        	} else {
        		lo = mid + 1;
        		ans = max(ans, two);
        	}
        }

        printf("%lld\n", ans);
    }


    return 0;
}



