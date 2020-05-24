class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mn = numeric_limits<int>::max();
        for (auto &x: prices) {
            mn = min(mn, x);
            ans = max(ans, x - mn);
        }
        return ans;
    }
};