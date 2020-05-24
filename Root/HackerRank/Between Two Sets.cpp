#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto& x: a) cin >> x;

    vector<int> b(m);
    for (auto& x: b) cin >> x;

    int ans = 0;
    for (int k = 1; k <= 100; k++) {
        int i, j;
        for (i = 0; i < n; i++) {
            if (k % a[i] != 0)
                break;
        }
        for (j = 0; j < m; j++) {
            if (b[j] % k != 0)
                break;
        }
        ans += (i == n && j == m);
    }

    cout << ans << endl;

    return 0;
}
