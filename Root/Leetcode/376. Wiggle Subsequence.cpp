class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ans = 1, mood = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                if (mood == 0 || mood == -1) {
                    mood = 1;
                    ans++;
                }
            } else if (nums[i] < nums[i - 1]) {
                if (mood == 0 || mood == 1) {
                    mood = -1;
                    ans++;
                }
            }
        }
        return ans;
    }
};
