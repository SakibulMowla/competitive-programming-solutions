#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    set<int> ms;
    int ans = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i >= k) {
            if (a[i] < *prev(ms.end())) {
                ans++;
            }
            ms.erase(a[i - k]);
        }

        ms.insert(a[i]);
    }

    cout << ans << endl;

    return 0;
}
