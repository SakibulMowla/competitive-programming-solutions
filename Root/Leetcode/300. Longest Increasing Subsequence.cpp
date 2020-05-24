class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector <long long> mark(n + 1, numeric_limits<long long>::max());
        mark[0] = numeric_limits<long long>::min();
        int lis = 0;
        
        for (int i = 0; i < n; i++) {
        	int lo = 0, hi = lis, indx;
        	while (lo <= hi) {
        		int mid = lo + (hi - lo) / 2;
        		if (nums[i] > mark[mid]) {
        			lo = mid + 1;
        		} else {
        			hi = mid - 1;
        		}
        	}
        	mark[lo] = nums[i];
        	lis = max(lis, lo);
        }
        return lis;
    }
};