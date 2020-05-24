#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> z, o, t;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x % 3 == 0) z.pb(x);
        else if (x % 3 == 1) o.pb(x);
        else t.pb(x);
        sum += x;
    }

    if (sum % 3 == 0) {
        cout << sum << endl;
    } else if (sum % 3 == 1) {
        sort(o.begin(), o.end());
        sort(t.begin(), t.end());
        int ans = 0;
        if (sz(o)) {
            ans = max(ans, sum - o[0]);
        }
        if (sz(t) >= 2) {
            ans = max(ans, sum - t[0] - t[1]);
        }
        cout << ans << endl;
    } else {
        sort(o.begin(), o.end());
        sort(t.begin(), t.end());
        int ans = 0;
        if (sz(t)) {
            ans = max(ans, sum - t[0]);
        }
        if (sz(o) >= 2) {
            ans = max(ans, sum - o[0] - o[1]);
        }
        cout << ans << endl;
    }

    return 0;
}


