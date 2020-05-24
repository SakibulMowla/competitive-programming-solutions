/*
ID: sakibul1
PROG: combo
LANG: C++
*/


#include "bits/stdc++.h"

using namespace std;

bool chk(int n, int a[], int b[]) {
    for (int i = 0; i < 3; i++) {
        int p = a[i], q = b[i];
        if (p < q) swap(p, q);
        if (p - q > 2 && n - p + q > 2) {
            return false;
        }
    }
    return true;
}

int main () {
//    freopen("combo.in", "r", stdin);
//    freopen("combo.out", "w", stdout);


    int n;
    cin >> n;

    int a[3], b[3], c[3];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                c[0] = i, c[1] = j, c[2] = k;
                if (chk (n, a, c) || chk (n, b, c)) {
                    ans++;
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
