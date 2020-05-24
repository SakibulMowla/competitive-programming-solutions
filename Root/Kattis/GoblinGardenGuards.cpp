#include <bits/stdc++.h>

using namespace std;

#define MAX 10010

struct Solve {
    vector < map <int, int>> points;
    int n, m;

    Solve(int n): n(n), points(MAX) {

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points[x][y]++;
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y, r;
            cin >> x >> y >> r;
            Del(x, y, r);
        }

        cout << FindAns() << endl;
    }

    void Del (int x, int y, int r) {
        for (int i = max(0, x - r); i <= min(10000, x + r); i++) {
            double d = sqrt(r*r - (i-x)*(i-x));
            int l = C((double)y - d);
            int r = F((double)y + d);
//            cout << ">> " << x << ' ' << i << ' ' << y << ' ' << d << ' ' << l << ' ' << r << endl;
            points[i].erase(points[i].lower_bound(l), points[i].upper_bound(r));
        }
    }

    int F (double d) {
        return (int)d;
    }

    int C (double d) {
        double dif = d - (int)d;
        return (dif > 0)? (int)d + 1: (int)d;
    }

    int FindAns () {
        int ans = 0;
        for (auto &x: points) {
            for (auto &i: x) {
                ans += i.second;
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    Solve Task(n);

    return 0;
}
