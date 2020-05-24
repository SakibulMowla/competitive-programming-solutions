#include <bits/stdc++.h>

using namespace std;

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

double dist(PT p, PT q)   {
    return sqrt(dist2(p, q));
}

double cross(PT p, PT q)   {
    return p.x*q.y-p.y*q.x;
}


int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <PT> pts(n + 2);

        for (int i = 1; i <= n; i++) {
            cin >> pts[i].x >> pts[i].y;
        }

        vector <double> dp(n + 2, INF);
        dp[0] = 0;
        dp[2] = dist(pts[1], pts[2]);

        for (int i = 3; i <= n; i++) {
            for (int j = i - 1, pre = i - 1; j >= 1; j--) {
                if (cross(pts[pre] - pts[i], pts[j] - pts[pre]) <= 0) { /// less or equal to 180 dergee turn
                    pre = j;
                    dp[i] = min(dp[i], dist(pts[i], pts[j]) + min(dp[j], dp[j-1]));
                }
            }
        }

        cout << fixed << setprecision(6) << dp[n] << endl;
    }

    return 0;
}


// <= 0
