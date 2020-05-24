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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <ll> a(n + 2), sumf(n + 2, 0), sumb(n + 2, 0);
        ll ans = -2E9;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ans = max(ans, a[i]);
        }

        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = max(a[i], a[i] + sum);
            sumf[i] = sum;
            ans = max(ans, sum);
        }

        sum = 0;
        for (int i = n; i >= 1; i--) {
            sum = max(a[i], a[i] + sum);
            sumb[i] = sum;
        }

        for (int i = 1; i <= n; i++) {
            ans = max(ans, sumf[i-1] + sumb[i+1]);
        }

        cout << ans << endl;
    }


    return 0;
}





