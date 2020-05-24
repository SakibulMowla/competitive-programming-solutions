#include <bits/stdc++.h>

using namespace  std;

double W, H, X, xe, ye, miu;

bool f (double h) {
    double p = xe - W;
    double q = ye - H;
    double d = sqrt((p * p * h * h) / (miu * miu * p * p + miu * miu * q * q - p * p));
    double x = W + (h - H) * (W - xe) / (H - ye);
    if (X + d >= 0.0 && X + d <= x) return true;
    return false;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%lf %lf %lf %lf %lf %lf", &W, &H, &X, &xe, &ye, &miu);

        bool flag = false;
        double ans, lo = 0, hi = H;

        for (int i = 0; i < 28; i++) {
//        for (int i = 0; i < 30; i++) {
            double h = (lo + hi) / 2.0;
            if (f(h)) {
                flag = true;
                ans = h;
                hi = h;
            } else {
                lo = h;
            }
        }

        if (flag) printf("%.4lf\n", ans);
        else printf("Impossible\n");
    }

    return 0;
}
