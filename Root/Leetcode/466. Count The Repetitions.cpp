class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int l1 = s1.size();
        int l2 = s2.size();

        vector < pair <int, int> > runner(l2);

        for (int i = 0; i < l2; i++) {
            int now = i;
            runner[i].second = 0;
            for (int j = 0; j < l1; j++) {
                if (s2[now] == s1[j]) {
                    now++;
                    if (now == l2) {
                        now = 0;
                        runner[i].second++;
                    }
                }
            }
            runner[i].first = now;
        }

        int tot = 0;
        vector <int> pre(l2 + 1, 0), dp(l2 + 1), indx(l2 + 1);
        pre[0] = -1;
        bool first = true;

        for (int i = 0, next = 0; i < n1; i++) {
            tot += runner[next].second;
            int x = pre[runner[next].first];
            if (x != 0 && first) {
                int len = i - (x != -1 ? indx[x] : x);
                int sum = tot - (x != -1 ? dp[x] : 0);
                int d = (n1 - i - 1) / len;
                if (d > 0) {
                    tot += d * sum;
                    i += d * len;
                }
                first = false;
            }
            dp[next] = tot;
            indx[next] = i;
            pre[runner[next].first] = next;
            next = runner[next].first;
        }

        return tot / n2;
    }
};
