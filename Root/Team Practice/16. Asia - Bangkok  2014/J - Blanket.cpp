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

int cnt[1024 * 1024], total[1024 * 1024];

int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(false);

    int t;
    scanf ("%d", &t);
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        scanf ("%d %d", &n, &m);
        VVI f(17, VI(17, 0));
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf ("%d %d", &a, &b);
            for (int i = 0; i < a; ++i) {
                f[b][i]++;
            }
        }
        for (int i = 0; i < m; ++i) {
            cnt[i] = 0;
        }
        for (int i = 0; i <= n; ++i) {
            total[i] = 0;
        }
        for (int i = 1; i <= 16; ++i) {
            for (int j = 0; j < m; ++j) {
                cnt[j] += f[i][j % i];
            }
        }
        for (int i = 0; i < m; ++i) {
            total[cnt[i]]++;
        }
        for (int i = 0; i <= n; ++i) {
            printf("%d\n", total[i]);
        }
    }

    return 0;
}
