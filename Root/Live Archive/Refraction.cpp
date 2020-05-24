#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

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
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%lf %lf %lf %lf %lf %lf", &W, &H, &X, &xe, &ye, &miu);

        bool flag = false;
        double ans, lo = 0, hi = H;

        for (int i = 0; i < 30; i++) {
            double h = (lo + hi) / 2.0;
//            printf("Before = %lf\n", h);
            if (f(h)) {
                flag = true;
                ans = h;
                hi = h;
            } else {
                lo = h;
            }
//            printf("After = %lf\n", h);
        }

        if (flag) printf("%.4lf\n", ans);
        else printf("Impossible\n");
//        cout << ans << endl;
    }


    return 0;
}







