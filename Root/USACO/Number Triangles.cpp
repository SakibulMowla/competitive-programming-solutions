/*
ID: sakibul1
PROG: numtri
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

#define SZ 1010

int a[SZ][SZ];
int n;
int dp[SZ][SZ];

int solve (int i, int j) {
    if (i == n + 1) {
        return 0;
    }
    int &ret = dp[i][j];
    if (~ret) return ret;

    ret = a[i][j] + max(solve(i + 1, j), solve(i + 1, j + 1));

    return ret;
}

int main () {
    ios::sync_with_stdio(0);

    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);

    cout << solve(1, 1) << '\n';

    return 0;
}
