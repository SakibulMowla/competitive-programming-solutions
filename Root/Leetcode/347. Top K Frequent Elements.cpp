class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> mp;
        set <pair<int, int>> ms;
        int n = nums.size();
        for (auto x: nums) mp[x] = 0;
        for (int i = 0; i < n; i++) {
            if (ms.find({mp[nums[i]], nums[i]}) != ms.end()) ms.erase(ms.find({mp[nums[i]], nums[i]}));
            mp[nums[i]]++;
            ms.insert({mp[nums[i]], nums[i]});
            if (ms.size() > k) ms.erase(ms.begin());
        }
        vector <int> ans;
        for (auto it: ms) ans.push_back(it.second);
        return ans;
    }
};