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

    int n, k;
    cin >> n >> k;

    vector <int> neg;
    int pre = 1, ans = 0;

    for (int i = 1; i <= n; i++) {
        int x, now = 1;
        cin >> x;

        if (x < 0) now = -1, k--;

        if (pre != now) {
            ans++;
            neg.pb(i);
        }
        pre = now;
    }

    if (k < 0) {
        cout << -1 << endl;
    } else {
        if (sz(neg) != 0) {
            vector <int> dif;
            for (int i = 2; i < sz(neg); i += 2) {
                dif.pb(neg[i] - neg[i-1]);
            }
            sort(dif.begin(), dif.end());

            int cash = k, ans1 = ans;

            if (sz(neg) % 2 == 0) {
                if (n - neg[sz(neg)-1] + 1 <= cash) {
                    cash -= (n - neg[sz(neg)-1] + 1);
                    ans1--;
                }
            }
            for (int i = 0; i < sz(dif); i++) {
                if (cash >= dif[i]) {
                    cash -= dif[i];
                    ans1 -= 2;
                }
            }

            int ans2 = ans;
            cash = k;

            for (int i = 0; i < sz(dif); i++) {
                if (cash >= dif[i]) {
                    cash -= dif[i];
                    ans2 -= 2;
                }
            }

            ans = min(ans1, ans2);
        }
        cout << ans << endl;
    }

    return 0;
}





