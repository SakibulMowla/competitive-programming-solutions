#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;


ll sum[100];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt;
    sum[1] = 1LL;
    for (int i = 2; ; i++) {
        sum[i] = sum[i-1] + (1LL<<(i-1));
        if(sum[i] >= 1E12) {
            cnt = i;
            break;
        }
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        double x;
        ll k;
        cin >> x >> k;

        int lo = 1, hi = cnt;
        int i;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (sum[mid] >= k) {
                i = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        double start = x / (double)(1LL<<i);
        double dif = 2.0 * start;
        k -= sum[i-1];
        double ans = start + ((double)k - 1.0) * dif;

        cout << fixed;
        cout << setprecision(12) << ans << '\n';
    }

    return 0;
}



