class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if (S > 1000 || S < -1000) return 0;
        
        int n = nums.size();
        
        vector<vector<int>> dp(2, vector<int> (2001, 0));
        dp[0][1000] = 1;
        
        for (int i = 0, now = 1, pre = 0; i < n; i++, now ^= 1, pre ^= 1) {
            dp[now] = vector<int> (2001, 0);
            for (int j = 0; j <= 2000; j++) {
                if (dp[pre][j] != 0) {
                    dp[now][j + nums[i]] += dp[pre][j];
                    dp[now][j - nums[i]] += dp[pre][j];
                }
            }
        }
        
        return dp[n & 1][S + 1000];
    }
};