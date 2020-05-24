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

typedef double T;
const T EPS = 1e-7;

struct PT {
    T x, y;
    PT() {}
    PT(T x, T y) : x(x), y(y) {}
    bool operator<(const PT &rhs) const {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator==(const PT &rhs) const {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};

T cross(PT p, PT q) {
    return p.x*q.y-p.y*q.x;
}

T area2(PT a, PT b, PT c) {
    return cross(a,b) + cross(b,c) + cross(c,a);
}

void ConvexHull(vector<PT> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<PT> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

double T_Search (vector <PT> &pts, int a, int b, int lo, int hi) {
    double ans = 0;
    int run = 50;
    while (run--) {
        int m1 = (2 * lo + hi) / 3;
        int m2 = (lo + 2 * hi) / 3;
        double A1 = abs(area2(pts[a], pts[b], pts[m1]));
        double A2 = abs(area2(pts[a], pts[b], pts[m2]));
        if (A1 > A2) {
            hi = m2;
            ans = max(ans, A1);
        } else {
            lo = m1;
            ans = max(ans, A2);
        }
        if (lo == hi) break;
    }
    return ans;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <PT> pts(n);

        for (auto &it: pts) {
            cin >> it.x >> it.y;
        }

        ConvexHull(pts);
        n = sz(pts);

        for (int i = 0; i < n; i++) {
            pts.pb(pts[i]);
        }

        double mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                mx = max(mx, T_Search(pts, i, j, i, j) + T_Search(pts, j, i, j, i + n));
            }
        }

        if ((ll)mx%2 == 0) cout << (ll)mx/2LL << endl;
        else cout << fixed << setprecision(1) << mx / 2.0 << endl;
    }


    return 0;
}




