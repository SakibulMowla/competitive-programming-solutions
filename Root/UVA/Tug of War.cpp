#include <bits/stdc++.h>

using namespace std;

int main () {
//    freopen("1.txt", "r", stdin);
//    freopen("2.txt", "w", stdout);

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        if (cs) {
            cout << endl;
        }

        int n;
        cin >> n;

        vector <int> a(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        vector <long long> dp(sum/2 + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = sum/2; j >= a[i]; j--) {
                dp[j] |= (dp[j-a[i]]<<1);
            }
        }

        for (int i = sum/2; i >= 0; i--) {
            if ((dp[i]&(1LL<<(n/2))) || (dp[i]&(1LL<<((n+1)/2)))) {
                cout << i << ' ' << sum - i << endl;
                break;
            }
        }
    }

    return 0;
}
