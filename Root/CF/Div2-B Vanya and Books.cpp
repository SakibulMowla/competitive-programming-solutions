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

ll calc (ll n, ll x, ll mul) {
    return n >= x ? mul * (min(x * 10LL, n + 1) - x) : 0;
}

ll solve (ll n) {
    ll ans = 0;
    ll x = 1;
    for (int i = 0; i < 10; i++) {
        ans += calc(n, x, i + 1);
        x *= 10LL;
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ll n;
    cin >> n;
    cout << solve(n) << endl;


    return 0;
}







