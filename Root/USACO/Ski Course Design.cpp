/*
ID: sakibul1
PROG: skidesign
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

#define SZ 1010

int a[SZ];

int main () {
//    freopen("skidesign.in", "r", stdin);
//    freopen("skidesign.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 1E8;
    for (int i = 0; i + 17 <= 100; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] < i) {
                tmp += (i - a[j]) * (i - a[j]);
            } else if (a[j] > i + 17) {
                tmp += (a[j] - i - 17) * (a[j] - i - 17);
            }
        }
        ans = min(ans, tmp);
    }

    cout << ans << '\n';

    return 0;
}
