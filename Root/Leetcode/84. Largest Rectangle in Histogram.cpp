class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
 		int n = heights.size();
 		stack <int> stk;
 		int ans = 0;
 		for (int i = 0; i < n; i++) {
 			while (stk.size() && heights[stk.top()] > heights[i]) {
 				int upper = heights[stk.top()]; stk.pop();
 				ans = max(ans, upper * (stk.size() ? i - 1 - stk.top() : i));
 			}
 			stk.push(i);
 		}       
 		while (stk.size()) {
 			int upper = heights[stk.top()]; stk.pop();
 			ans = max(ans, upper * (stk.size() ? n - 1 - stk.top() : n));
 		}
 		return ans;
    }
};