#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int n, int k, vector<int>& heights) {
    int prev = 0;
    for (int height: heights) {
        int jump = height - prev;
        if (jump == k) {
            k--;
        } else if (jump > k) {
            return false;
        }
        prev = height;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int t = 0; t < cases; t++) {
        int n;
        cin >> n;

        int lo = 0;
        int hi = 0;

        vector<int> heights(n);
        for (int& height: heights) {
            cin >> height;
            hi = max(hi, height + 1);
        }

        int ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (binarySearch(n, mid, heights)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        cout << "Case " << t + 1 << ": " << ans << '\n';
    }

    return 0;
}
