#include "stdio.h"
#include "algorithm"
#include "iostream"

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    bool operator < (const Point &rhs) const {
        return make_pair(y,x) < make_pair(rhs.y,rhs.x);
    }
    bool operator == (const Point &rhs) const {
        return make_pair(y,x) == make_pair(rhs.y,rhs.x);
    }
};

long long cross (Point a, Point b) {
    return (long long)a.x * (long long)b.y - (long long)a.y * (long long)b.x;
}

long long area2 (Point a, Point b, Point c) {
    return cross(a, b) + cross(b, c) + cross(c, a);
}

bool between(const PT &a, const PT &b, const PT &c) {
    return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}

void ConvexHull(vector<Point> &pts) {
    sort(pts.begin(), pts.end());
    vector<Point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

    ///For removing redundant points
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
    ///For removing redundant points
}

int main() {

    return 0;
}

/*
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
*/
