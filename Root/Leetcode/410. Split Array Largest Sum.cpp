class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();

        long long lo = 0, hi = 0, ans = numeric_limits<long long>::max();
        for (auto x: nums) hi += x;

        while (lo <= hi) {
            long long mid = (lo + hi) / 2;
            int part = m;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                if (sum + nums[i] <= mid) sum += nums[i];
                else {
                    part--;
                    if (nums[i] <= mid) sum = nums[i];
                    else part = 0;
                }
                if (part == 0) break;
            }
            if (part) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        return ans;
    }
};
