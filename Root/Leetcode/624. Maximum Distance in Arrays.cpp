class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        multiset<int> ms;
        int n = arrays.size();
        for (int i = 0; i < n; i++) {
            if (arrays[i].size()) ms.insert(arrays[i][arrays[i].size() - 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arrays[i].size()) {
                ms.erase(ms.find(arrays[i][arrays[i].size() - 1]));
                ans = max(ans, *prev(ms.end()) - arrays[i][0]);
                ms.insert(arrays[i][arrays[i].size() - 1]);
            }
        }
        return ans;
    }
};