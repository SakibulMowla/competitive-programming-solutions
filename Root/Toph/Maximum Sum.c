#include <stdio.h>

#define SZ 1001
#define ll long long

ll sum[SZ], dp[SZ], a[SZ];

int main() {
    int t;
    scanf("%d", &t);

    int cs;
    for (cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        int i;
        for (i = 1; i <= n; i++) {
            scanf("%lld", &a[i]);
            sum[i] = a[i] + sum[i - 1];
            dp[i] = -100000000000000;
        }

        for (i = 1; i <= n; i++) {
            int j;
            for (j = 0; j < i; j++) {
                ll tmp = dp[j] + (sum[i] - sum[j]) * (ll)(i - j);
                if (tmp > dp[i]) dp[i] = tmp;
            }
        }

        printf("%lld\n", dp[n]);
    }

    return 0;
}
