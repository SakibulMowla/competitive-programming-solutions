class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = numeric_limits<int>::min(), buy2 = numeric_limits<int>::min();
        int sell1 = 0, sell2 = 0;
        for (auto &x: prices) {
            buy1 = max(buy1, -x);
            sell1 = max(sell1, buy1 + x);
            buy2 = max(buy2, sell1 - x);
            sell2 = max(sell2, buy2 + x);
        }
        return sell2;
    }
};
