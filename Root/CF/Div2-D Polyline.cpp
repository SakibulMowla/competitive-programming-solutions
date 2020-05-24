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

bool check (pii& a, pii& b, pii& c) {
    return (a.X == b.X && a.Y == c.Y) || (a.X == c.X && a.Y == b.Y);
}

bool chick (pii& a, pii& b, pii& c) {
    return (a.X == b.X && a.X == c.X) || (a.Y == b.Y && a.Y == c.Y);
}

bool chicks (pii a, pii b, pii c) {
    if (a.X == b.X && (c.Y <= min(a.Y, b.Y) || c.Y >= max(a.Y, b.Y))) return true;
    swap(a.X, a.Y);
    swap(b.X, b.Y);
    swap(c.X, c.Y);
    if (a.X == b.X && (c.Y <= min(a.Y, b.Y) || c.Y >= max(a.Y, b.Y))) return true;
    return false;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    vector <pii> a(3);
    while (cin >> a[0].X >> a[0].Y >> a[1].X >> a[1].Y >> a[2].X >> a[2].Y) {
        vector <int> b(6);
        b[0] = a[0].X;
        b[1] = a[0].Y;
        b[2] = a[1].X;
        b[3] = a[1].Y;
        b[4] = a[2].X;
        b[5] = a[2].Y;
        int ans = 3;
        if (check(a[0], a[1], a[2]) || check(a[1], a[0], a[2]) || check(a[2], a[0], a[1])) ans = 2;
        if (chicks(a[0], a[1], a[2]) || chicks(a[1], a[2], a[0]) || chicks(a[2], a[0], a[1])) ans = 2;
        if (chick(a[0], a[1], a[2])) ans = 1;
//        for (int mask = 1; mask < (1<<6); mask++) if (__builtin_popcount(mask) == 3) {
//            vector <bool> flag(3, false);
//            for (int i = 0; i < 6; i++) if (mask & (1<<i)) {
//                if (i % 2 == 0) {
//                    for (int j = 0; j < 3; j++) {
//                        if (b[i] == a[j].X) {
//                            flag[j] = true;
//                        }
//                    }
//                } else {
//                    for (int j = 0; j < 3; j++) {
//                        if (b[i] == a[j].Y) {
//                            flag[j] = true;
//                        }
//                    }
//                }
//            }
//            if (flag[0] == true && flag[1] == true && flag[2] == true) {
//                ans = min(ans, __builtin_popcount(mask));
//            }
//        }
        assert(ans <= 3);
        cout << ans << endl;
    }


    return 0;
}





