class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector <int> among(3);
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
            among[0] = nums[i];
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[j] + nums[k];

                if (sum < -nums[i]) j++;
                else if (sum > -nums[i]) k--;
                else {
                    among[1] = nums[j];
                    among[2] = nums[k];
                    ans.push_back(among);
                    while (j < k && nums[j] == among[1]) j++;
                    while (j < k && nums[k] == among[2]) k--;
                }
            }

            while (i + 1 < n && nums[i + 1] == among[0]) i++;
        }

        return ans;
    }
};
