#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define SZ 110

int main() {
    ios_base::sync_with_stdio(false);

    ll f[SZ], sum[SZ];

    f[1] = f[2] = 1;
    sum[1] = 1; sum[2] = 2;

    for (int i = 3; i <= 90; i++) {
        f[i] = f[i-1] + f[i-2];
        sum[i] = f[i] + sum[i-1];
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll n;
        cin >> n;
        for (int i = 1; ; i++) {
            if (sum[i] >= n) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}
