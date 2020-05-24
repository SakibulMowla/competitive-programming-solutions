class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, 0);
        return ans;
    }

    void solve (vector<vector<int>>& ans, vector <int>& nums, int now) {
        if (now == nums.size()) {
            ans.push_back(nums);
        } else {
            for (int i = now; i < nums.size(); i++) {
                swap(nums[i], nums[now]);
                solve(ans, nums, now + 1);
                swap(nums[i], nums[now]);
            }
        }
        return;
    }
};
