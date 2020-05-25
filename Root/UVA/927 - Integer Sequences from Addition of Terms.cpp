#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;

    while (cases--) {
        int len;
        cin >> len;

        vector<ll> an(len + 1);
        for (auto& x: an) cin >> x;

        ll d, k;
        cin >> d >> k;

        ll lo = 1, hi = 2000, n;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2LL;
            ll tmpk = mid * (mid + 1LL) * d / 2LL;
            if (tmpk >= k) {
                n = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        ll ans = 0, running_n = 1;
        for (auto& c: an) {
            ans += c * running_n;
            running_n *= n;
        }

        cout << ans << '\n';
    }

    return 0;
}

