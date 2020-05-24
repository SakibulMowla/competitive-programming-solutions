#include "bits/stdc++.h"

#define ll long long

int main() {
    ll cnt1, cnt2, x, y;

    while(scanf("%I64d %I64d %I64d %I64d", &cnt1, &cnt2, &x, &y) == 4) {
        ll lo = (cnt1 + cnt2);
        ll hi = 3LL * (cnt1 + cnt2);
        ll ans = 0LL;

        while(lo <= hi) {
            ll mid = (lo + hi) >> 1LL;
            ll a = mid / x;
            ll b = mid / y;
            ll c = mid / (x * y);
            if( (mid-a) >= cnt1 && (mid-b) >= cnt2 && (mid-c) >= (cnt1+cnt2) ) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        printf("%I64d\n", ans);
    }

    return 0;
}
