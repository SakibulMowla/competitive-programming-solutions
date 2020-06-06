#include <iostream>
 
using namespace std;
using ll = long long;
 
int main() {
    ios::sync_with_stdio(false);
 
    int tests;
    cin >> tests;
 
    while (tests--) {
        ll h, c, t;
        cin >> h >> c >> t;
 
        if (2 * t <= h + c) {
            cout << 2 << '\n';
            continue;
        }
 
        ll lo = 1, hi = 1E6, step;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2;
 
            if (h * mid + c * (mid - 1) < t * (2 * mid - 1)) {
                hi = mid - 1;
            } else {
                step = mid;
                lo = mid + 1;
            }
        }
 
        ll stepTempSum = (2 * step + 1) * (h * step + c * (step - 1));
        ll stepAfterTempSum = (2 * step - 1) * (h * (step + 1) + c * step);
        ll idealTempSum = t * (2 * step - 1) * (2 * step + 1);
        if (abs(stepTempSum - idealTempSum) > abs(stepAfterTempSum - idealTempSum)) {
            step++;
        }
 
        cout << 2 * step - 1 << '\n';
    }
 
    return 0;
}
