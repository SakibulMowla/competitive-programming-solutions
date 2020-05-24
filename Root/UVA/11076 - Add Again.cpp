#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);

    vector <ll> ten(13), fact(13);

    fact[0] = 1LL;
    for (int i = 1; i <= 12; i++) {
        fact[i] = (ll)i * fact[i-1];
    }

    ten[0] = 1LL;
    for (int i = 1; i <= 12; i++) {
        ten[i] = 10LL * ten[i-1];
    }

    int n;
    while (cin >> n && n) {
        vector <int> a(n);
        map <int, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        ll ans = 0LL;

        for (auto itr: mp) {
            mp[itr.first]--;

            ll tfact = fact[n-1];
            for (auto it: mp) {
                tfact /= fact[it.second];
            }

            for (int j = n - 1; j >= 0; j--) {
                ans += (ll)itr.first * tfact * ten[j];
            }

            mp[itr.first]++;
        }

        cout << ans << endl;
    }


    return 0;
}







