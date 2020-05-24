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

    int n, zeros = 0;
    cin >> n;

    vector <int> a(n + 2), sum(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        zeros += (int)(a[i] == 0);
    }

    if (zeros == n) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        vector <pii> ans;
        int pre = 0;
        while (true) {
            if (sum[n] - sum[pre] != 0) {
                ans.pb({pre + 1, n});
                break;
            }
            for (int i = n - 1; ; i--) {
                if (sum[i] - sum[pre] != 0) {
                    ans.pb({pre + 1, i});
                    pre = i;
                    break;
                }
            }
        }
        cout << sz(ans) << endl;
        for (auto x: ans) {
            cout << x.X << ' ' << x.Y << endl;
        }
    }

    return 0;
}





