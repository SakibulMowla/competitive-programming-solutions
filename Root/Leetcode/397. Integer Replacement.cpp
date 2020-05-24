class Solution {
public:
    int solve (int indx, int carry, int& msb, int& n, vector<vector<int>>& dp) {
        if (indx == msb) return carry;
        int &ret = dp[indx][carry];
        if (ret != -1) return ret;

        int now = ((n >> indx) & 1);
        int bit = now ^ carry;
        carry = carry & now;

        if (bit == 0) ret = 1 + solve(indx + 1, carry, msb, n, dp);
        else {
            ret = 2 + solve(indx + 1, 0, msb, n, dp);
            ret = min(ret, 2 + solve(indx + 1, 1, msb, n, dp));
        }
        return ret;
    }

    int integerReplacement(int n) {
        int msb;
        for (msb = 31; msb >= 0; msb--) if ((n >> msb) & 1) break;
        vector<vector<int>> dp(msb + 1, vector<int>(2, -1));
        return solve(0, 0, msb, n, dp);
    }
};
