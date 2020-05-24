#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

using VI = vector <int>;

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        VI a = VI(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            VI cnt = VI(n+1, 0);
            int even = 0, odd = 0;
            for (int j = 1; j <= n; j++) {
                cnt[j] = cnt[j-1] + ((a[j]>>i)&1);
                if (cnt[j]&1) odd++;
                else even++;
            }
            ll tmp = 0;
            int flip = 0;
            for (int j = 1; j <= n; j++) {
                tmp += odd;
                if (!flip) {
                    if (cnt[j]&1) {
                        odd--;
                        swap(even, odd);
                        flip ^= 1;
                    }
                    else even--;
                } else {
                    if (cnt[j]&1) {
                        even--;
                    } else {
                        odd--;
                        swap(even, odd);
                        flip ^= 1;
                    }
                }
            }
            ans += tmp * (1LL<<i);
        }

        cout << ans << endl;
    }

    return 0;
}





