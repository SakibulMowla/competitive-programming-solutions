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


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; ++cs) {
        int s, c;
        cin >> s >> c;
        VVI dp (c + 1, VI (s, 0)), profit (s, VI(c)), dist (s, VI (s));

        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> profit[i][j];
            }
        }
        for (int i = 0; i < s; ++i) {
            for (int j = 0; j < s; ++j) {
                cin >> dist[i][j];
            }
        }

        for (int i = 0; i < s; ++i) {
            dist[i][i] = 0;
        }

        for (int i = 1; i <= c; ++i) {
            for (int j = 0; j < s; ++j) {
                for (int k = 0; k < s; ++k) {
                    dp[i][j] = max (dp[i - 1][k] - dist[k][j] + profit[j][i - 1], dp[i][j]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s; ++i) {
            ans = max(ans, dp[c][i]);
        }
        cout << ans << endl;
    }

    return 0;
}
