class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> mark(n, vector<bool> (n, false));
        
        for (int i = 0; i < n; i++) mark[i][i] = true;
        for (int i = 0; i < n - 1; i++) mark[i][i + 1] = (s[i] == s[i + 1]);
        for (int k = 3; k <= n; k++) {
            for (int i = k - 1, j = 0; i < n; i++, j++) {
                mark[j][i] = (s[j] == s[i] && mark[j + 1][i - 1] == true);
            }
        }
        
        vector<int> dp(n, numeric_limits<int>::max());
        for (int i = 0; i < n; i++) if (mark[0][i] == true) dp[i] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (mark[i][j] == true) {
                    dp[j] = min(dp[j], dp[i - 1] + 1);
                }
            }
        }
        
        return dp[n - 1];
    }
};