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

int get (int i, int j, VVI &x) {
    if (i < sz(x) && j < sz(x[i])) {
        return x[i][j];
    }
}

int main(int argc, char const *argv[]) {
    // ios::sync_with_stdio(false);

    int t;
    scanf ("%d", &t);
    for (int cs = 0; cs < t; ++cs) {
        int n, m;
        scanf ("%d %d", &n, &m);
        VVI x(n, VI(m));
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &x[i][j]);
                if (x[i][j] == -1) {

                } else if ((i + j) % 2 == 0) {
                    ans += x[i][j];
                } else {
                    ans -= x[i][j];
                }
            }
        }
        printf("%d\n", abs(ans));
    }

    return 0;
}
