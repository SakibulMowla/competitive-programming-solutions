class Solution {
public:
    vector < vector < vector <int> > > dp;
    int mod = 1E9 + 7;

    int solve (int indx, int Abs, int contLate) { // calling it with (n - 1, 0, 0) will produce correct answer but generate RTE due to stack limit exceeded
        if (Abs == 2 || contLate == 3) return 0;
        if (indx == -1) return 1;

        int &ret = dp[indx][Abs][contLate];
        if (ret != -1) return ret;

        ret = solve(indx - 1, Abs + 1, 0);
        ret = ret + solve(indx - 1, Abs, contLate + 1); if (ret >= mod) ret -= mod;
        ret = ret + solve(indx - 1, Abs, 0); if (ret >= mod) ret -= mod;

        return ret;
    }

    int checkRecord(int n) {
        dp = vector < vector < vector <int> > > (2, vector < vector <int> > (2, vector <int> (3, 0)));

        dp[0][0][0] = 1;
        int cur = 0, pre = 1;

        for (int i = 1; i <= n; i++) { // day
            swap(cur, pre);
            dp[cur] = vector < vector <int> > (2, vector <int> (3, 0));
            for (int j = 0; j <= 1; j++) { // absent
                for (int k = 0; k <= 2; k++) { // late
                    dp[cur][j][0] += dp[pre][j][k]; if (dp[cur][j][0] >= mod) dp[cur][j][0] -= mod;
                    if (j == 1) {
                        dp[cur][j][0] += dp[pre][j - 1][k];
                        if (dp[cur][j][0] >= mod) dp[cur][j][0] -= mod;
                    }
                    if (k >= 1) {
                        dp[cur][j][k] += dp[pre][j][k - 1];
                        if (dp[cur][j][k] >= mod) dp[cur][j][k] -= mod;
                    }
                }
            }
        }

        int ans = dp[cur][0][0];
        ans += dp[cur][0][1]; if (ans >= mod) ans -= mod;
        ans += dp[cur][0][2]; if (ans >= mod) ans -= mod;
        ans += dp[cur][1][0]; if (ans >= mod) ans -= mod;
        ans += dp[cur][1][1]; if (ans >= mod) ans -= mod;
        ans += dp[cur][1][2]; if (ans >= mod) ans -= mod;

        return ans;
    }
};
