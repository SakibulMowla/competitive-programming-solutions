class Solution {
public:
    int findPeakElement(vector<int>& nums) {
  		int n = nums.size();
  		int ans, lo = 0, hi = n - 1;
  		
  		while (lo <= hi) {
  			if (lo == hi) {
  				ans = lo;
  				break;
  			}

  			if (lo + 1 == hi) {
  				if (nums[lo] > nums[hi]) ans = lo;
  				else ans = hi;
  				break;
  			}

  			int mid = lo + (hi - lo) / 2;
  			
  			if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
  				ans = mid;
  				break;
  			}

  			if (nums[mid] > nums[mid - 1] && nums[mid + 1] > nums[mid]) {
  				lo = mid + 1;
  			} else {
  				hi = mid - 1;
  			}
  		}   
  		
  		return ans;
    }
};