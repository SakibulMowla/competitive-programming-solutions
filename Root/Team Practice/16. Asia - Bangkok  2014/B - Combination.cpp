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
typedef unsigned long long ll;
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

ll f[128];

ll find (ll x, int n) {
    if (x == -1) {
        return 0;
    } else if (x == 0) {
        return 1;
    } else if (x >= (1LL << n)) {
        return f[n] + 2LL * find (x - (1LL << n), n - 1);
    } else {
        return find (x, n - 1);
    }
}


int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);

    for (int i = 0; i < 128; ++i) {
        f[i] = i == 0 ? 1 : 3LL * f[i - 1];
    }

    ll l, r;
    while (cin >> l >> r && ! (l == 0 && r == 0)) {
        cout << find (r, 50) - find(l - 1, 50) << endl;
    }

    return 0;
}
