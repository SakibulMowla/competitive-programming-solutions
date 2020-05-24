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

    ll n, k;
    cin >> n >> k;

    vector <ll> a(n);
    for (auto &x: a) cin >> x;

    int n1 = n / 2, n2 = n - n1;
    vector <ll> set1, set2;

    for (int mask = 0; mask < (1 << n1); mask++) {
        ll mul = 1;
        for (int i = 0; i < n1; i++) {
            if (mask & (1 << i)) {
                if (mul <= k / a[i]) mul *= a[i];
                else {
                    mul = k + 1;
                    break;
                }
            }
        }
        if (mul <= k) set1.push_back(mul);
    }

    for (int mask = 0; mask < (1 << n2); mask++) {
        ll mul = 1;
        for (int i = 0; i < n2; i++) {
            if (mask & (1 << i)) {
                if (mul <= k / a[i + n1]) mul *= a[i + n1];
                else {
                    mul = k + 1;
                    break;
                }
            }
        }
        if (mul <= k) set2.push_back(mul);
    }

    sort(set2.begin(), set2.end());

    int ans = 0;
    for (auto mul: set1) {
        int lo = 0, hi = sz(set2) - 1, indx;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mul <= k / set2[mid]) {
                indx = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        ans += indx + 1;
    }

    cout << ans - 1 << endl;

    return 0;
}





