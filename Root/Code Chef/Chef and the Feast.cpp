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

        ll posCnt = 0, posSum = 0, negSum = 0;
        vector <ll> neg;

        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            if (x < 0) {
                neg.pb(x);
                negSum += x;
            } else {
                posCnt++;
                posSum += x;
            }
        }

        sort(neg.begin(), neg.end());
        reverse(neg.begin(), neg.end());
        vector <ll> sum(neg.size(), 0);
        if (neg.size()) sum[0] = neg[0];
        for (int i = 1; i < neg.size(); i++) sum[i] = sum[i - 1] + neg[i];
        ll ans = posCnt * posSum + negSum;

        for (int i = 0; i < neg.size(); i++) {
            if ((posSum + sum[i]) * (posCnt + i + 1) + negSum - sum[i] > ans) {
                ans = (posSum + sum[i]) * (posCnt + i + 1) + negSum - sum[i];
            }
        }

        cout << ans << endl;
    }

    return 0;
}





