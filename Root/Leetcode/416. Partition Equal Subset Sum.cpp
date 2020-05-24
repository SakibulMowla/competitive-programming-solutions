class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto x: nums) sum += x;
        if (sum & 1) return false;
        vector <bool> dp(sum / 2 + 1, 0);
        dp[0] = true;
        sum /= 2;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};