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
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector <int> last(n + 2, -1);

    for (int i = 0; i < q; i++) {
        int t, k, d;
        cin >> t >> k >> d;

        vector <int> got;
        for (int j = 1; j <= n; j++) {
            if (t > last[j]) {
                got.pb(j);
                if (sz(got) == k) {
                    break;
                }
            }
        }

        if (sz(got) == k) {
            int ans = 0;
            for (int j = 0; j < k; j++) {
                ans += got[j];
                last[got[j]] = t + d - 1;
            }
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}





