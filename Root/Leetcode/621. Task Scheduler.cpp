class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() == 0) return 0;
        vector <int> cnt(26, 0), pre(26, -1);
        for (auto x: tasks) cnt[x - 'A']++;
        int ans = 0, off = 100;
        while (true) {
            bool flag = false;
            int mx = 0, indx = 0;
            for (int i = 0; i < 26; i++) {
                if (cnt[i] > mx && (pre[i] == -1 || ans - pre[i] >= n)) {
                    mx = cnt[i];
                    indx = i;
                    flag = true;
                }
            }
            if (flag == false) {
                for (int i = 0; i < 26; i++) {
                    if (cnt[i] > mx) {
                        mx = cnt[i];
                        indx = i;
                        flag = true;
                    }
                }
            }
            if (flag == false) {
                break;
            }
            ++ans;
            cnt[indx]--;
            if (pre[indx] == -1 || ans - pre[indx] - 1 >= n) {
                pre[indx] = ans;
            } else {
                ans = pre[indx] + n + 1;
                pre[indx] = ans;
            }
        } 
        return ans;
    }
};