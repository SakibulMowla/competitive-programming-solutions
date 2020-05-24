class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans = numeric_limits<int>::min(), sum = 0;
        int mx = numeric_limits<int>::min();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (sum < 0) sum = 0;
            else ans = max(ans, sum);
            if (nums[i] < 0) mx = max(mx, nums[i]);
        }
        return max(ans, mx);
    }
};
