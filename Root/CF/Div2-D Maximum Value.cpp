#include <bits/stdc++.h>

using namespace  std;

#define SZ 200010

int x[SZ], xsz;

int main()
{
    int n;
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);

        sort(x, x+n);
        xsz = unique(x, x+n) - x;

        int mx = x[xsz-1];
        int ans = 0;

        for (int i = 0; i < xsz; i++) {
            for (int j = x[i]; j <= mx + x[i]; j += x[i]) {
                int idx = lower_bound(x+i, x+xsz, j) - x;
                if (idx == 0 || x[idx-1] < x[i]) continue;
                ans = max(ans, x[idx-1] % x[i]);
            }
        }

        printf("%d\n", ans);
    }


    return 0;
}


