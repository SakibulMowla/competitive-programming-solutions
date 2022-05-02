#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    
    int n;

    while (cin >> n) {
        vector<int> nums(n);

        for (int& num: nums) {
            cin >> num;
            // cout << ">> " << num << endl;
        }

        sort(nums.begin(), nums.end());

        int mid1 = nums[(n - 1) / 2], mid2 = nums[n / 2];
        int count = 0;
        for (int i = 0; i < n; i++) {
            // cout << ">>> " << nums[i] << ' ' << nums[mid1] << ' ' << nums[mid2] << endl;
            if (nums[i] == mid1 || nums[i] == mid2) {
                count++;
            }
        }
        int range = mid2 - mid1 + 1;

        cout << mid1 << ' ' << count << ' ' << range << endl;
    }
    
    return 0;
}
