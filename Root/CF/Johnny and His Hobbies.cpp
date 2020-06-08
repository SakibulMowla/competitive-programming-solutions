#include <algorithm>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;

        set<int> collection;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            collection.insert(x);
        }

        int ans = -1;

        for (int k = 1; k <= 1024; k++) {
            vector<bool> found(1025, false);
            bool isHalted = false;

            for (auto x: collection) {
                int y = x ^ k;
                if (collection.find(y) == collection.end() || found[y]) {
                    isHalted = true;
                    break;
                }
                found[y] = true;
            }

            if (!isHalted) {
                ans = k;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
