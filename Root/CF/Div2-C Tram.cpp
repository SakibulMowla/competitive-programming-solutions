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


#define SZ 1010


int main() {
    ios::sync_with_stdio(false);

    int s, x1, x2, t1, t2, p, dirt, dirl;
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> dirt;

    if (x2 > x1) dirl = 1;
    else dirl = -1;

    int ans = abs(x2 - x1) * t2;

    vector <int> point(s + 2, -1);

    point[p] = 0;
    if (dirt == 1) {
        for (int i = p + 1; i <= s; i++) {
            point[i] = point[i - 1] + t1;
        }
    } else {
        for (int i = p - 1; i >= 0; i--) {
            point[i] = point[i + 1] + t1;
        }
    }

    if (point[x1] != -1 && point[x2] != -1 && point[x2] > point[x1]) {
        ans = min(ans, point[x2]);
    } else {
        if (dirt == 1) {
            for (int i = s - 1; i >= 0; i--) {
                point[i] = point[i + 1] + t1;
            }
        } else {
            for (int i = 1; i <= s; i++) {
                point[i] = point[i - 1] + t1;
            }
        }
        if (point[x1] != -1 && point[x2] != -1 && point[x2] > point[x1]) {
            ans = min(ans, point[x2]);
        }
    }
    if (dirt == -1) {
        for (int i = s - 1; i >= 0; i--) {
            point[i] = point[i + 1] + t1;
        }
    } else {
        for (int i = 1; i <= s; i++) {
            point[i] = point[i - 1] + t1;
        }
    }
    if (point[x1] != -1 && point[x2] != -1 && point[x2] > point[x1]) {
        ans = min(ans, point[x2]);
    }

    cout << ans << endl;

    return 0;
}





