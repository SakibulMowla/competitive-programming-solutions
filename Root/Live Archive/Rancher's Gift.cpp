#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

#define SZ  110

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

double dist(PT p, PT q)   {
    return sqrt(dot(p-q,p-q));
}

double dist2(PT p, PT q)   {
    return dot(p-q,p-q);
}

double cross(PT p, PT q)   {
    return p.x*q.y-p.y*q.x;
}

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b=b-a;
    d=c-d;
    c=c-a;
    assert(dot(b, b) > EPS && dot(d, d) > EPS);
    return a + b*cross(c, d)/cross(b, d);
}

PT mid (PT a, PT b) {
    return (a + b) / 2.0;
}

double TriArea (PT a, PT b, PT c) {
    double d = a.x * (b.y - c.y) - a.y * (b.x - c.x) + (b.x * c.y - b.y * c.x);
    return d / 2.0 / 160.0;
}

int main() {
    #if defined JESI
                freopen("1.txt", "r", stdin);
                freopen("2.txt", "w", stdout);
    #endif


    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int test;
        PT a, b, c, d;

        a.x = a.y = 0;
        b.y = 0;

        cin >> test >> b.x >> c.x >> c.y >> d.x >> d.y;

        PT ab = ComputeLineIntersection(a, mid(b, c), b, mid(c, d));
        PT bc = ComputeLineIntersection(c, mid(d, a), b, mid(c, d));
        PT cd = ComputeLineIntersection(d, mid(a, b), c, mid(d, a));
        PT da = ComputeLineIntersection(a, mid(c, b), d, mid(a, b));

        double al = TriArea(a, b, ab);
        double bob = TriArea(b, c, bc);
        double chas = TriArea(c, d, cd);
        double dave = TriArea(d, a, da);
        double emily = TriArea(da, ab, bc) + TriArea(da, bc, cd);
        double fence = ceil((dist(ab, bc) + dist(bc, cd) + dist(cd, da) + dist(da, ab)) * 16.5);

        cout << fixed << setprecision(3) << test << ' ' << al << ' ' << bob << ' ' << chas << ' ' << dave << ' ' << emily << ' ' << (int)fence << '\n';
    }


    return 0;
}


/*

3
1 200 250 150 -50 200
2 200 200 100 0 100
3 201.5 157.3 115.71 -44.2 115.71

*/
