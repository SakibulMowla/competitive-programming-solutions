#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using VL = vector<ll>;

int main() {
    ios::sync_with_stdio(false);

    ll n, m;
    cin >> n >> m;

    VL caffeine(n);
    for (auto&x: caffeine) {
        cin >> x;
    }

    sort(caffeine.rbegin(), caffeine.rend());

    int lo = 1, hi = n, ans = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        ll sum = 0;
        for (int i = 0; i < n; i += mid) {
            for (int j = 0; j < mid && i + j < n; j++) {
                sum += max(0LL, caffeine[i + j] - i / mid);
            }
        }
        if (sum >= m) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
