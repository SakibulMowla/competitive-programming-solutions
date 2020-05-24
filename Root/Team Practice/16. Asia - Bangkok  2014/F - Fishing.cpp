#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define R(a) ((a)%mod)

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef pair<ll, ll> PI;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef vector<double> VD;
typedef vector<VD> VVD;

int fish[128][128];
int mind[128][128][128], maxd[128][128][128];
int minc[128][128][128], maxc[128][128][128];

int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(false);
    // initialize
    int t;
    scanf ("%d", &t);
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        scanf ("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &fish[i][j]);
            }
        }
        for (int k = 1; k <= min(m, n); ++k) {
            for (int i = 0; i <= n; ++i) {
                for (int j = 0; j <= m; ++j) {
                    maxc[k][i][j] = 0;
                    minc[k][i][j] = 2000000000;
                }
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    maxd[k][i][j] = fish[i][j] + maxc[k - 1][i - 1][j - 1];
                    mind[k][i][j] = fish[i][j] + minc[k - 1][i - 1][j - 1];

                    maxc[k][i][j] = max (maxd[k][i][j], max (maxc[k][i-1][j], maxc[k][i][j-1]));
                    minc[k][i][j] = min (mind[k][i][j], min (minc[k][i-1][j], minc[k][i][j-1]));
                }
            }
        }
        int ans = 0;
        for (int k = 1; 2 * k <= min (m, n); ++k) {
            ans = max (ans, maxc[k][n][m] - minc[2 * k][n][m]);
        }
        printf("%d\n", ans);
    }

    return 0;
}
