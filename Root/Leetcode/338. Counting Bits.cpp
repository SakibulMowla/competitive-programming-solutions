class Solution {
public:
    vector<int> countBits(int num) {
        int ones = 0, n = 0;
        vector<int> ans(num + 1);
        for (int i = 1; i <= num; i++) {
            int bit = 0;
            while (n & (1 << bit)) {
                n &= ~(1 << bit);
                bit++;
                ones--;
            }
            n |= (1 << bit);
            ones++;
            ans[i] = ones;
        }
        return ans;
    }
};