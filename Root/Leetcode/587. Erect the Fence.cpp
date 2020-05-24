#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

bool comp(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

class Solution {
public:
    long long cross (Point a, Point b) {
        return (long long)a.x * (long long)b.y - (long long)a.y * (long long)b.x;
    }

    long long area2 (Point a, Point b, Point c) {
        return cross(a, b) + cross(b, c) + cross(c, a);
    }

    void ConvexHull(vector<Point> &pts) {
        sort(pts.begin(), pts.end(), comp);
        vector<Point> up, dn;
        for (int i = 0; i < pts.size(); i++) {
            while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
            while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
            up.push_back(pts[i]);
            dn.push_back(pts[i]);
        }
        pts = dn;
        for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
        int n = pts.size();
        sort(pts.begin(), pts.end(), comp);
        for (int i = n - 1; i >= 0; i--) {
            if (i - 1 >= 0 && pts[i].x == pts[i - 1].x && pts[i].y == pts[i-1].y) {
                pts.erase(pts.begin() + i);
            }
        }
    }

    vector<Point> outerTrees(vector<Point>& points) {
        ConvexHull(points);
        return points;
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    Solution sol;
    vector <Point> a, b;
//    [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
    a.push_back(Point(1, 1));
    a.push_back(Point(2, 2));
    a.push_back(Point(2, 0));
    a.push_back(Point(2, 4));
    a.push_back(Point(3, 3));
    a.push_back(Point(4, 2));
//    a.push_back(Point(1, 2));
//    a.push_back(Point(2, 2));
//    a.push_back(Point(4, 2));

    b = sol.outerTrees(a);
    for (auto x: b) cout << x.x << ' ' << x.y << endl;

    return 0;
}




