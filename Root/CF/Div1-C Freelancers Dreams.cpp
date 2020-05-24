#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


double INF = 1e100;
double EPS = 1e-12;

struct PT {
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const {
        return PT(x/c,   y/c  );
    }
    bool operator<(const PT &rhs) const {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator==(const PT &rhs) const {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};

double dot(PT p, PT q)     {
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q)   {
    return dot(p-q,p-q);
}

#define REMOVE_REDUNDANT true

typedef double T;

T cross(PT p, PT q) {
    return p.x*q.y-p.y*q.x;
}
T area2(PT a, PT b, PT c) {
    return cross(a,b) + cross(b,c) + cross(c,a);
}

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

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

#ifdef REMOVE_REDUNDANT
    if (pts.size() <= 2) return;
    dn.clear();
    dn.push_back(pts[0]);
    dn.push_back(pts[1]);
    for (int i = 2; i < pts.size(); i++) {
        if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
        dn.push_back(pts[i]);
    }
    if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
        dn[0] = dn.back();
        dn.pop_back();
    }
    pts = dn;
#endif
}

PT ProjectPointSegment(PT a, PT b, PT c) {
    double r = dot(b-a,b-a);
    if (fabs(r) < EPS) return a;
    r = dot(c-a, b-a)/r;
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

bool PointInPolygon(const vector<PT> &p, PT q) {
    bool c = 0;
    int lim = sz(p);
    for (int i = 0; i < lim; i++) {
        int j = (i+1 == lim)? 0: i+1;
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

bool PointOnPolygon(const vector<PT> &p, PT q) {
    int lim = sz(p);
    for (int i = 0; i < lim; i++)
        if (dist2(ProjectPointSegment(p[i], p[(i+1 == lim)? 0: i+1], q), q) < EPS)
            return true;
    return false;
}

int main() {
#if defined JESI
    //    freopen("1.txt", "r", stdin);
    //    freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    double p, q;
    cin >> n >> p >> q;

    vector <PT> pts;
    double X = 0, Y = 0;

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        pts.pb(PT(x, y));
        X = max(X, x);
        Y = max(Y, y);
    }

    pts.pb(PT(X, 0));
    pts.pb(PT(0, Y));
    pts.pb(PT(0, 0));

    ConvexHull(pts);

    int lim = 45;
    double lo = 0, hi = 2000000, ans;

    for (int i = 0; i < lim; i++) {
        double mid = (lo + hi) / 2.0;
        PT a = PT(p/mid, q/mid);
        if (PointInPolygon(pts, a) || PointOnPolygon(pts, a)) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}



