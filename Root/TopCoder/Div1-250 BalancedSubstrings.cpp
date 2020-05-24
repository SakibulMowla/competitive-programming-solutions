#include <bits/stdc++.h>

using namespace std;

class BalancedSubstrings {
public:
	int countSubstrings(string s) {
		int n = s.size();
		int ans = 0;
		for (int i = 0; i < n; i++) {
            map <int, int> cnt;
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += (s[j] - '0') * (i - j);
                cnt[sum]++;
            }
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += (s[j] - '0') * (j - i);
                if (s[i] == '1' || sum) {
                    ans += cnt[sum];
                }
            }
		}
		int cnt = 0;
		for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                cnt++;
            } else {
                ans += cnt * (cnt + 1) / 2;
                cnt = 0;
            }
		}
		ans += cnt * (cnt + 1) / 2;
		return ans;
	}
};
