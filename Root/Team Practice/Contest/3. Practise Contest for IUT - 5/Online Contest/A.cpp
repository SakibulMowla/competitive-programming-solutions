#include <cmath>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>
#include <map>
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

int t, n;
VVI w, debt;
VI dp;

int find (int mask) {
    if (dp[mask] != -1) {
        return dp[mask];
    }
    if(__builtin_popcount(mask) == 1) {
        dp[mask] = mask;
        return dp[mask];
    }

    dp[mask] = 0;

    for (int i = 0; i < n; ++i) if ((mask & (1 << i)) && debt[i][mask] > 0) {
        dp[mask] |= find(mask ^ (1 << i));
    }
    return dp[mask];
}

int main(int argc, char const *argv[]) {
    cin >> t;
    for (int cs = 0; cs < t; ++cs) {
        cin >> n;

        w = VVI(n, VI(n));
        debt = VVI(n, VI((1<<n), 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> w[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int b = 0; b < n; ++b) {
                for (int mask = (1 << b); mask < (1 << (b+1)); ++mask) {
                    debt[i][mask] = debt[i][mask ^ (1 << b)] + w[i][b];
                }
            }
        }
        dp = VI((1 << n), -1);
        int mask = find((1 << n) - 1);
        if (mask == 0) {
            cout << 0 << '\n';
        } else {
            int first = true;
            for (int i = 0; i < n; ++i) if(mask & (1 << i)) {
                if (!first) {
                    cout << ' ';
                } else {
                    first = false;
                }
                cout << i + 1;
            }
            cout << '\n';
        }

    }
    return 0;
}
