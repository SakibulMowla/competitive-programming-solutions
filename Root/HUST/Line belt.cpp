#include <bits/stdc++.h>

using namespace  std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair <double , double> pdd;

#define SZ 100010

double dist (pdd a, pdd b) {
    return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}

pdd a, b, c, d;
double p, q, r;

double ternary (pdd m) {
    double ans = 1E16, ans1, ans2;
    pdd lo = c, hi = d;
    pdd m1, m2;

    for (int i = 0; i < 100; i++) {
        m1.X = (lo.X + hi.X) / 2.0;
        m1.Y = (lo.Y + hi.Y) / 2.0;
        m2.X = (m1.X + hi.X) / 2.0;
        m2.Y = (m1.Y + hi.Y) / 2.0;
        ans1 = dist(m, m1) / r + dist(m1, d) / q;
        ans2 = dist(m, m2) / r + dist(m2, d) / q;
        if (ans1 < ans2) {
            ans = min(ans, ans1);
            hi = m2;
        } else {
            ans = min(ans, ans2);
            lo = m1;
        }
    }

    return ans;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> d.X >> d.Y >> p >> q >> r;

        double ans = 1E16, ans1, ans2;
        pdd lo = a, hi = b;
        pdd m1, m2;

        for (int i = 0; i < 100; i++) {
            m1.X = (lo.X + hi.X) / 2.0;
            m1.Y = (lo.Y + hi.Y) / 2.0;
            m2.X = (m1.X + hi.X) / 2.0;
            m2.Y = (m1.Y + hi.Y) / 2.0;
            ans1 = dist(a, m1) / p + ternary(m1);
            ans2 = dist(a, m2) / p + ternary(m2);
            if (ans1 < ans2) {
                ans = min(ans, ans1);
                hi = m2;
            } else {
                ans = min(ans, ans2);
                lo = m1;
            }
        }

        cout << fixed << setprecision(2) << ans << endl;
    }


    return 0;
}







