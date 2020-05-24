#include "bits/stdc++.h"

using namespace std;
using ll = long long;

#define SZ 1000010

#define X first
#define Y second

int dp[SZ];
pair <int, int> vp[SZ];

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        for (int i = 0; i <= 100000; i++) {
            dp[i] = 0;
            vp[i] = {-1, -1};
        }

        int n, q, last = 1;
        scanf("%d %d", &n, &q);

        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
//            while (x < 1 || x > 100000);
//            while (y < 1 || y > 100000);
            last = max(last, y);
            dp[x]++;
            dp[y]--;
        }
        for (int i = 1; i <= last; i++) {
            dp[i] += dp[i-1];
        }

        for (int i = 1; i <= last; i++) {
            int j = i;
            for (; j <= last && dp[j] == dp[i]; j++) {
                ;
            }
            --j;
            int range = dp[i];
            if (vp[range].first == -1 || (vp[range].Y - vp[range].X) < (j - i)) {
                vp[range] = {i, j};
            }
            i = j;
        }

        printf("Case %d:\n", cs + 1);
        for (int i = 0; i < q; i++) {
            int l;
            scanf("%d", &l);

            if (vp[l].X == -1)  printf("-1\n");
            else printf("%d %d\n", vp[l].X, vp[l].Y);
        }
    }

    return 0;
}
