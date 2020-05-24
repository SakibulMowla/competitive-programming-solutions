class Solution {
public:
    int hIndex(vector<int>& citations) {
         int n = citations.size();
         vector <int> cnt(n + 2, 0);
         for (auto x: citations) 
         	if (x > n) cnt[n]++;
         	else cnt[x]++;
         int ans = 0;
         for (int i = n; i >= 0; i--) {
         	cnt[i] += cnt[i + 1];
         	if (cnt[i] >= i) {
         		ans = i;
         		break;
         	}
         }
         return ans;
    } 
};