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
};

double dot(PT p, PT q)     {
    return p.x*q.x+p.y*q.y;
}
double dist2(PT p, PT q)   {
    return dot(p-q,p-q);
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
    for (int i = 0; i < p.size(); i++) {
        int j = (i+1)%p.size();
        if ((p[i].y <= q.y && q.y < p[j].y ||
                p[j].y <= q.y && q.y < p[i].y) &&
                q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
            c = !c;
    }
    return c;
}

bool PointOnPolygon(const vector<PT> &p, PT q) {
    for (int i = 0; i < p.size(); i++)
        if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
            return true;
    return false;
}

int main() {
    #if defined JESI
    //    freopen("1.txt", "r", stdin);
    //    freopen("2.txt", "w", stdout);
    #endif

    long long int n, m;
    while (cin >> n >> m) {
//        double portion = 1. - 1. / pow(2., n);
        cout << fixed << setprecision(50) << ' ' << pow(1. - 1. / pow(2., n), m) << endl;
    }

    return 0;
}


