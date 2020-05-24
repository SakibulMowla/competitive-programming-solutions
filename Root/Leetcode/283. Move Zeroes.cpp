class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        for ( ; r < n; r++) {
            if (nums[r] != 0) {
                nums[l++] = nums[r];
            }
        }
        for ( ; l < n; l++) nums[l] = 0;
    }
};
