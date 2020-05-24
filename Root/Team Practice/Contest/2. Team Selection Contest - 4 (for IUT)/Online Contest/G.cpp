#include <cstdio>
#include <vector>
#include <algorithm>

#define pb push_back
#define x first
#define y second
#define mp make_pair
#define sz(a) ((int)(a).size())
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

int t, n, m;
VD a, b, c;
VVD dp;

double f (double a) {
    return double(int(a * 1000.0)) / 1000.0;
}

int main() {
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d %d", &n, &m);

        a = VD(n), b = VD(n), c = VD(n);
        dp = VVD(n+1, VD(m+1));

        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            a[i] /= 100.0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%lf", &b[i]);
            b[i] /= 100.0;
        }
        for (int i = 0; i < n; i++) {
            c[i] = 1.0 - a[i] - b[i];
        }

        dp[0] = VD(m+1, 15000.0);

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                dp[i][j] = a[i-1] * dp[i-1][j] - b[i-1] * dp[i-1][j] + c[i-1] * dp[i-1][j];
                if (j >= 1) {
                    dp[i][j] = min(dp[i][j], a[i-1] * dp[i-1][j-1] - b[i-1] * dp[i-1][j-1] - c[i-1] * dp[i-1][j-1]);
                }
//                printf(">> %d %d %lf\n", i, j, dp[i][j]);
            }
        }

        printf("Case #%d: %.3lf\n", cs, f(dp[n][m]));
    }

    return 0;
}
