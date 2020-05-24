#include <iostream>
#include <vector>

using namespace std;
using PII = pair<int, int>;

int main() {
    ios::sync_with_stdio(false);

    int k;
    while (cin >> k) {
        vector<PII> ans;
        for (int y = k + 1; y <= 2 * k; y++) {
            if (0 == (y * k) % (y - k)) {
                int x = (y * k) / (y - k);
                ans.push_back({x, y});
            }
        }
        cout << ans.size() << '\n';
        for (auto item: ans) {
            int x = item.first, y = item.second;
            cout << "1/" << k << " = 1/" << x << " + 1/" << y << '\n';
        }
    }

    return 0;
}

