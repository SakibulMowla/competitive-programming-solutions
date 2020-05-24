#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int m, s;
        cin >> m >> s;

        vector<vector<int>> dp(s + 1, vector<int> (s + 1, numeric_limits<int>::max()));
        dp[0][0] = 0;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            for (int j = x; j <= s; j++) {
                for (int k = y; k <= s; k++) {
                    if (dp[j - x][k - y] != numeric_limits<int>::max()) {
                        dp[j][k] = min(dp[j][k], 1 + dp[j - x][k - y]);
                        //cout << ">> " << j << " " << k << " " << dp[j][k] << endl;
                    }
                }
            }
        }

        int ans = numeric_limits<int>::max();
        for (int j = 0; j <= s; j++) {
            int k = s * s - j * j;
            double d = sqrt(k);
            //cout << ">> d = " << d << endl;
            if (d == (int)d) {
                ans = min(ans, dp[j][(int)d]);
            }
        }

        cout << (ans == numeric_limits<int>::max() ? "not possible" : to_string(ans)) << endl;
    }

    return 0;
}