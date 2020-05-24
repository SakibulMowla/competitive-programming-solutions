#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 100000007;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k, s;
        cin >> n >> k >> s;

        vector<vector<ll> > dp(2, vector<ll> (s + 1, 0));
        vector<vector<ll> > sum(2, vector<ll> (s + 1, 0));
        
        dp[0][0] = 1;
        for (int i = 0; i <= s; i++) sum[0][i] = 1;
        int cur = 0;

        for (int i = 1; i <= n; i++) {
            cur ^= 1;
            sum[cur][0] = 0;
            for (int j = 1; j <= s; j++) {
                int lo = 1; 
                int hi = min(k, j);
                dp[cur][j] = sum[cur ^ 1][j - lo] - (j - hi - 1 >= 0 ? sum[cur ^ 1][j - hi - 1] : 0);
                if (dp[cur][j] >= mod) dp[cur][j] -= mod;
                if (dp[cur][j] < 0) dp[cur][j] += mod;
                sum[cur][j] = dp[cur][j] + sum[cur][j - 1];
                if (sum[cur][j] >= mod) sum[cur][j] -= mod;
            }
        }

        cout << "Case " << cs + 1 << ": " << dp[cur][s] << endl;
    }

    return 0;
}

/*
5
1 6 3
2 9 8
500 6 1000
800 800 10000
2 100 10

Case 1: 1
Case 2: 7
Case 3: 57286574
Case 4: 72413502
Case 5: 9
*/