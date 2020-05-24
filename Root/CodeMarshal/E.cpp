#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back
#define sz(a) (int)a.size()

#define SZ 100010

const ll inf = 1;
const ll mod = 1;

int a[SZ];

int main () {
    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n, x;
        scanf("%d %d", &n, &x);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        int lo = 1, hi = 1E9, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                sum += (ll)a[i] / (ll)mid;
            }
            if (sum >= x) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        printf("Case %d: %lld\n", cs + 1, (ll)ans * (ll)x);
    }

    return 0;
}

