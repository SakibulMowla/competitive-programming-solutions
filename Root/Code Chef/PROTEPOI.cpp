#include <bits/stdc++.h>

using namespace  std;

#define pb push_back

#define X first
#define Y second

typedef pair <int, int> pii;

int solve (vector <pii>& a, int from, int to) {
//    cout << ">> " << from << ' ' << to << endl;
    int lastCovered = from - 1;
    set <int> ms;
    sort(a.begin(), a.end());
    int cnt = 0;
    for (auto x: a) {
//        cout << ">> LC = " << lastCovered << endl;
//        cout << ">> " << x.X << ' ' << x.Y << endl;
        if (x.X <= lastCovered + 1) {
            ms.insert(x.Y);
        } else {
            if (!ms.empty()) lastCovered = *prev(ms.end());
            cnt++;
            if (lastCovered >= to) return cnt;
            if (x.X > lastCovered + 1) return -1;
            ms.insert(x.Y);
        }
    }
    return (!ms.empty() && *prev(ms.end()) >= to) ?  cnt + 1 : -1;
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k, m;
        cin >> n >> k >> m;

        vector <pii> horizontal, vertical;

        for (int i = 0; i < m; i++) {
            pii u, v;
            cin >> u.X >> u.Y >> v.X >> v.Y;
            if (u == v) {
                if (u.X < (n - k) / 2 + 1 || u.X > n - (n - k) / 2) horizontal.pb({u.Y, v.Y});
                else vertical.pb({u.X, v.X});
            } else if (u.X == v.X) {
                if (u.X >= (n - k) / 2 + 1 && u.X <= n - (n - k) / 2) vertical.pb({u.X, v.X});
                else horizontal.pb({min(u.Y, v.Y), max(u.Y, v.Y)});
            } else {
                if (u.Y >= (n - k) / 2 + 1 && u.Y <= n - (n - k) / 2) horizontal.pb({u.Y, v.Y});
                else vertical.pb({min(u.X, v.X), max(u.X, v.X)});
            }
        }

        int k1 = solve(horizontal, (n - k) / 2 + 1, n - (n - k) / 2);
        int k2 = solve(vertical, (n - k) / 2 + 1, n - (n - k) / 2);

        cout << ((k1 == -1 || k2 == -1) ? -1 : k1 + k2) << endl;
    }

    return 0;
}
