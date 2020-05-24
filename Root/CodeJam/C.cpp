#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;

vector<int> weights;
int dp[101][6001];
int col[101][6001];
int now;

int solve(int indx, int sum) {
    if (indx == -1 || sum > 6000) return 0;
    if (col[indx][sum] == now) return dp[indx][sum];
    col[indx][sum] = now;
    dp[indx][sum] = solve(indx - 1, sum);
    if (weights[indx] * 6 >= sum) dp[indx][sum] = max(dp[indx][sum], 1 + solve(indx - 1, sum + weights[indx]));
    return dp[indx][sum];
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        weights = vector<int> (n);
        for (auto& x: weights) cin >> x;
        reverse(weights.begin(), weights.end());
        ++now;

        cout << "Case #" << cs + 1 << ": " << solve(n - 1, 0) << endl;
    }

    return 0;
}






