#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 100010

const ll inf = 1;
const ll mod = 1;



int main () {
    ios::sync_with_stdio(false);

    double dp[501];
    dp[1] = 0;
    for (int i = 2; i <= 500; i++) {
        dp[i] = dp[i - 1] + 1.0 / ((double)i - 1.0);
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        cout << fixed << setprecision(6) << "Case " << cs + 1 << ": " << dp[n] << endl;
    }

    return 0;
}


