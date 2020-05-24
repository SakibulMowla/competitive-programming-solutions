#include <bits/stdc++.h>

using namespace  std;

double calc(vector <double> &a, double x) {
    double sum = 0, mx = 0, mn = 0;
    for (auto d: a) {
        sum += d - x;
        mx = max(mx, sum);
        mn = min(mn, sum);
    }
    return (mx-mn);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector <double> a(n);
        for (auto &d: a) {
            cin >> d;
        }

        double lo = -10000, hi = 10000, ans = 1e16;

        for (int i = 0; i < 100; i++) {
            double midL = (2.0 * lo + hi) / 3.0;
            double midR = (lo + 2.0 * hi) / 3.0;
            double thetaL = calc(a, midL);
            double thetaR = calc(a, midR);
            if (thetaL < thetaR) {
                ans = min(ans, thetaL);
                hi = midR;
            } else {
                ans = min(ans, thetaR);
                lo = midL;
            }
        }

        cout << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}
