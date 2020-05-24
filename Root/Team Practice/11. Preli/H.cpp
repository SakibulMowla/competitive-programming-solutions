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
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef vector<PI> VPI;
typedef vector<PL> VPL;
typedef vector<VPI> VVPI;
typedef vector<long double> VD;
typedef vector<VD> VVD;

const ll mod = 1000000007;

ll fpow (ll a, ll n) {
    if (n == 0) return 1;
    ll ret = fpow (a, n / 2LL);
    ret = R(ret * ret);
    return n % 2 == 1 ? R(ret * a) : ret;
}

ll f[100500], g[100500];

int main (int argc, char const *argv[]) {
     ios::sync_with_stdio(false);
     cin.tie(0);

    for (int i = 0; i < 100500; ++i) {
        f[i] = i == 0 ? 1 : R(f[i - 1] * ll(i));
        g[i] = fpow(f[i], mod - 2LL);
    }

    int t;
     cin >> t;
//    scanf("%d", &t);
    for (int cs = 0; cs < t; ++cs) {
        int m, n;
//        scanf("%d %d", &m, &n);
         cin >> m >> n;
//        printf("Case %d: %lld\n", cs + 1, R(f[m + n] * R(g[m] * g[n])));
         cout << "Case " << cs + 1 << ": " << R(f[m + n] * R(g[m] * g[n])) << endl;
    }

    return 0;
}
