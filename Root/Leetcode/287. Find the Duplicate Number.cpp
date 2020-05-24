class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 1, hi = n - 1, ans;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int cnt = 0;
            for (auto x: nums)
                if (x <= mid)
                    cnt++;
            if (cnt <= mid) lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        return ans;
    }
};
