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



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int p, x, y, ox;
    cin >> p >> x >> y;
    ox = x;

    vector <bool> flag(500, false);
    for (int i = 0; i < 480; i++) {
        int ii = i;
        for (int j = 1; j <= 25; j++) {
            ii = (ii * 96 + 42) % 475;
            if (ii + 26 == p) {
                flag[i] = true;
                break;
            }
        }
    }

    int ans = 100000000;
    for (int i = x; ; i += 50) {
        if (flag[(i / 50) % 475] == true && i >= y) {
            ans = (i - x + 99) / 100;
            break;
        }
    }

    for (int i = x - 50; i >= y; i -= 50) {
        if (flag[(i / 50) % 475] == true && i >= y) {
            ans = 0;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}





