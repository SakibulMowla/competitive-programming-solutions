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
//    #if defined JESI
        freopen("grave.in", "r", stdin);
        freopen("grave.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    int w, h;
    cin >> w >> h;

    if ((x2 - x1 >= w && (y3 - y1 >= h || y2 - y4 >= h)) ||
        (x2 - x4 >= w && y2 - y1 >= h) ||
        (x3 - x1 >= w && y2 - y1 >= h)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}





