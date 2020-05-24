#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
        cin >> diff[i];
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        diff[i] -= x;
    }

    sort(diff.begin(), diff.end());

    ll ans = 0;

    for (int l = 0, r = n - 1; l < n - 1; l++) {
        r = max(r, l + 1);

        while (r - 1 > l && diff[l] + diff[r - 1] > 0) {
            r--;
        }

        if (diff[l] + diff[r] > 0) {
            ans += n - r;
        }
    }

    cout << ans << endl;

    return 0;
}
