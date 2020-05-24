#include <stdio.h>
#include <deque>

using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int pre1 = 0, pre2 = 1E9, cnt1 = 0, cnt2 = 0;
    long long ans1 = 0, ans2 = 0;
    deque<int> dq1, dq2;

    for (int i = 1; i <= n; i++) {
        int cur;
        scanf("%d", &cur);

        if (cur >= pre1) {
            cnt1++;
        } else {
            dq1.push_back(cnt1);
            ans1 += 1LL * cnt1 * (cnt1 - 1) / 2LL;
            cnt1 = 1;
        }

        if (cur <= pre2) {
            cnt2++;
        } else {
            dq2.push_back(cnt2);
            ans2 += 1LL * cnt2 * (cnt2 - 1) / 2LL;
            cnt2 = 1;
        }

        if (i > k) {
            if (dq1.size()) {
                ans1 -= 1LL * dq1[0] * (dq1[0] - 1) / 2LL;
                dq1[0]--;
                if (dq1[0] == 0) {
                    dq1.pop_front();
                } else {
                    ans1 += 1LL * dq1[0] * (dq1[0] - 1) / 2LL;
                }
            } else {
                cnt1--;
            }

            if (dq2.size()) {
                ans2 -= 1LL * dq2[0] * (dq2[0] - 1) / 2LL;
                dq2[0]--;
                if (dq2[0] == 0) {
                    dq2.pop_front();
                } else {
                    ans2 += 1LL * dq2[0] * (dq2[0] - 1) / 2LL;
                }
            } else {
                cnt2--;
            }
        }

        if (i >= k) {
            printf("%lld\n", ans1 + 1LL * cnt1 * (cnt1 - 1) / 2LL - ans2 - 1LL * cnt2 * (cnt2 - 1) / 2LL);
        }

        pre1 = pre2 = cur;    
    }

    return 0;
}