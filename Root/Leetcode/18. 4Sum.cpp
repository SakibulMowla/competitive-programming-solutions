class Solution {
public:

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int targetP = target - nums[i] - nums[j];
                int strt = j + 1, endd = n - 1;
                while (strt < endd) {
                    if (nums[strt] + nums[endd] < targetP) strt++;
                    else if (nums[strt] + nums[endd] > targetP) endd--;
                    else {
                        vector <int> tmp = {nums[i], nums[j], nums[strt], nums[endd]};
                        ans.push_back(tmp);
                        while (strt < endd && nums[strt] == tmp[2]) strt++;
                        while (strt < endd && nums[endd] == tmp[3]) endd--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j]) j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) i++;
        }

        return ans;
    }
};
