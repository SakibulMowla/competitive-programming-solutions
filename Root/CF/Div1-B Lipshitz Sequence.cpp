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

    int n, q;
    while (cin >> n >> q) {
        vector <ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = n - 1; i > 0; i--) {
            a[i] = abs(a[i] - a[i-1]);
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;

            ll sum = 0, ans = 0;
            stack <pll> stk;

            for (int i = l + 1; i <= r; i++) {
                pll x = {a[i], 1};
//                cout << ">> " << i << ' ' << a[i] << endl;
                while (!stk.empty()) {
                    if (stk.top().X < x.X) {
                        x.Y += stk.top().Y;
                        sum -= stk.top().X * stk.top().Y;
                        stk.pop();
                    } else {
                        break;
                    }
                }
                sum += x.X * x.Y;
                stk.push(x);
                ans += sum;
            }

            cout << ans << endl;
        }
    }


    return 0;
}





