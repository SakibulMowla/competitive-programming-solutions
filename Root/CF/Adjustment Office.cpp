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
//    #if defined JESI
//        freopen("adjustment.in", "r", stdin);
//        freopen("adjustment.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    ll rsum = ((ll)n * (ll)(n + 1)) / 2LL;
    ll csum = ((ll)n * (ll)(n + 1)) / 2LL;

    set <int> msr, msc;

    for (int cs = 0; cs < q; cs++) {
        char c;
        int x;
        cin >> c >> x;

        if (c == 'R') {
            if (msr.find(x) == msr.end()) {
                ll ans = (ll)x * (ll)(n - sz(msc));
                ans = ans + csum;
                cout << ans << endl;
                msr.insert(x);
                rsum -= (ll)x;
            } else {
                cout << 0 << endl;
            }
        } else {
            if (msc.find(x) == msc.end()) {
                ll ans = (ll)x * (ll)(n - sz(msr));
                ans = ans + rsum;
                cout << ans << endl;
                msc.insert(x);
                csum -= (ll)x;
            } else {
                cout << 0 << endl;
            }
        }
    }


    return 0;
}




