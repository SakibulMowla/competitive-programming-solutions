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

struct Solve {
    int w, n;
    int mx;
    vector <pii> a;
    vector <int> P, point;

    Solve (int w, int n): w(w), n(n), a(n), mx(0), P(n), point(n) {
        for (auto& it: a) {
            string s;
            cin >> s >> it.second;
            it.first = sz(s);
            mx = max(mx, it.second);
        }

        for (int i = 0; i < n; i++) {
            P[i] = 8 + C(40.0 * (a[i].second - 4.0) / (mx - 4.0));
        }

        for (int i = 0; i < n; i++) {
            point[i] = C(9.0 * a[i].first * P[i] / 16.0);
        }
    }

    int C(double x) {
        double d = x - (int)x;
        return (d > 0)? (int)x + 1: (int)x;
    }

    int FindAns() {
        int ans = 0;
        bool space = false;
        for (int i = 0, nowH = 0, nowW = 0; i < n; i++) {
            if (nowW + point[i] + (space? 10: 0) > w) {
                nowW = point[i];
                ans += nowH;
                nowH = P[i];
                space = true;
            } else {
                nowW += point[i] + (space? 10: 0);
                space = true;
                nowH = max(nowH, P[i]);
            }
            if (i == n - 1) {
                ans += nowH;
            }
        }
        return ans;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int w, n, cs = 0;
    while (cin >> w >> n && (w + n)) {
        Solve Task(w, n);
        cout << "CLOUD " << ++cs << ": " << Task.FindAns() << endl;
    }


    return 0;
}




