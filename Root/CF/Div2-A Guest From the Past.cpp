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

ll cal1 (ll n, ll a, ll b, ll c, ll d) {
    ll ans = n / a;
    n = n - ans * a;
    if (n >= b) ans += (n - b + d) / d;
    return ans;
}

ll cal2 (ll n, ll a, ll b, ll c, ll d) {
    ll ans = 0;
    if (n >= b) ans = (n - b + d) / d;
    n = n - ans * d;
    ans += n / a;
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);


    ll n, a, b, c;
    while (cin >> n >> a >> b >> c) {
        ll d = b - c;
        cout << max(cal1(n, a, b, c, d), cal2(n, a, b, c, d)) << endl;
    }

    return 0;
}





