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

    int n, m;
    cin >> n >> m;

    vector<pii> v(m);
    for (auto &x: v) {
        cin >> x.X >> x.Y;
        if (x.X == n) {
            cout << x.Y << endl;
            return 0;
        }
    }

    int cnt = 0;
    vector<int> ans;

    for (int flats = 1; flats <= 107; flats++) {
        bool flag = true;
        for (auto x: v) {
            int flor = x.X / flats + (bool)(x.X % flats);
            if (flor != x.Y) {
                flag = false;
                break;
            }
        }
        if (flag == true) {
            cnt++;
            ans.push_back(flats);
        }
    }

    set<int> R;
    for (auto x: ans) {
        R.insert(n / x + (bool)(n % x));
    }

    if (sz(R) == 1) {
        cout << *R.begin() << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}





