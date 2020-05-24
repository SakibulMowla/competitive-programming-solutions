#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 100000007;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector<int> a(n);
        int sum = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        vector<ll> dp1(sum + 1, -1), dp2(sum + 1, -1);
        dp1[0] = dp2[0] = 0;

        int lim = 0;
        for (int i = 0; i < n; i++) {
            lim += a[i];
            for (int j = a[i]; j <= lim; j++) if (dp1[j] == -1 && dp1[j - a[i]] != -1 && (0 == ((dp1[j - a[i]] >> i) & 1))) {
                dp1[j] = (dp1[j - a[i]] | (1LL << i));
            }
        }

        reverse(a.begin(), a.end());

        int ans = 0;
        lim = 0;
        for (int i = 0; i < n; i++) {
            lim += a[i];
            for (int j = a[i]; j <= lim; j++) if (dp2[j] == -1 && dp2[j - a[i]] != -1 && (0 == ((dp1[j - a[i]] >> (n - i - 1)) & 1))) {
                dp2[j] = (dp2[j - a[i]] | (1LL << (n - i - 1)));
                if (dp1[j] != -1 && 0 == (dp1[j] & dp2[j])) {
                    ans = max(ans, j);
                    if (j == 58) cout << ">> " << dp1[j] << ' ' << dp2[j] << endl;
                } 
            }
        }        

        cout << dp1[64] << ' ' << dp2[64] << endl;

        cout << "Case " << cs + 1 << ": " << ans << endl;
    }

    return 0;
}

/*
4
3
3 4 7
3
10 9 2
2
21 21
9
15 15 14 24 14 3 20 23 15

Case 1: 7
Case 2: impossible
Case 3: 21
Case 4: 64
*/