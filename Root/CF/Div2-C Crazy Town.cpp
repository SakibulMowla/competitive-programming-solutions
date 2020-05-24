#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

bool dir (ll x, ll y, ll a, ll b, ll c) {
    return (a*x + b*y + c > 0);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    ll x1, y1, x2, y2;
    int n;

    cin >> x1 >> y1 >> x2 >> y2 >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (dir(x1, y1, a, b, c) != dir(x2, y2, a, b, c)) {
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}







