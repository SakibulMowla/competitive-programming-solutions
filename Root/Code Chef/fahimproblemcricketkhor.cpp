#include "bits/stdc++.h"

using namespace std;

int dp[12][302][302];

int solve (int batsman, int balls_left, int pre) {
    int &ret = dp[batsman][balls_left][pre];
    if (ret != -1) return ret;

    if (batsman == 0 || balls_left == 0) return ret = 0;

    ret = 0;
    for (int i = 1; i <= balls_left; i++) {
        ret = max(ret, pre + solve(batsman - 1, balls_left - i, i));
    }

    return ret;
}

void path (int batsman, int balls_left, int pre) {
    int &ret = dp[batsman][balls_left][pre];

    if (batsman == 0 || balls_left == 0) return;

    for (int i = 1; i <= balls_left; i++) {
        if (pre + solve(batsman - 1, balls_left - i, i) == ret) {
            cout << ">> batsman = " << batsman << " Run = " << pre << " Ball = " << i << endl;
            return path(batsman - 1, balls_left - i, i);
        }
    }

    return;
}

int main () {
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);
    cout << 57 + solve(10, 300 - 38, 38) << endl;
    cout << ">> batsman = " << 11 << " Run = " << 57 << " Ball = " << 38 << endl;
    path(10, 300 - 38, 38);

    return 0;
}
