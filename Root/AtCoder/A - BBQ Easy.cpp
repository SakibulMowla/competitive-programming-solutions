#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(2 * n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < 2 * n; i += 2)
        ans += a[i];

    cout << ans << endl;

    return 0;
}
