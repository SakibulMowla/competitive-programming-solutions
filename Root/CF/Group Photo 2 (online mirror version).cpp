#include <bits/stdc++.h>

using namespace  std;

int main() {
    int n;
    cin >> n;

    vector <int> w(n);
    vector <int> h(n);

    int minH = 0, maxH = 0;

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> h[i];
        minH = max(minH, min(w[i], h[i]));
        maxH = max(maxH, max(w[i], h[i]));
    }

    int ans = 1E9;

    for (int height = minH; height <= maxH; height++) {
        int width = 0;
        int inv = 0;
        vector <int> tmp;

        for (int i = 0; i < n; i++) {
            if (h[i] > height) {
                inv++;
                width += h[i];
            } else if (w[i] > height) {
                width += w[i];
            } else {
                width += w[i];
                tmp.push_back(w[i] - h[i]);
            }
        }

        if (inv > n/2) continue;

        stable_sort(tmp.rbegin(), tmp.rend());

        for (int i = 0; i < tmp.size() && inv < n/2 && tmp[i] > 0; i++) {
            width -= tmp[i];
            inv++;
        }

        ans = min(ans, width * height);
    }

    cout << ans << '\n';

    return 0;
}

