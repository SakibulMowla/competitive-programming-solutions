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

    int n, l, r;
    cin >> n >> l >> r;

    vector <int> a(n), p(n), b(n);

    for (auto &x: a) {
        cin >> x;
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p[x - 1] = i;
    }

    b[p[0]] = l;
    int pre = b[p[0]] - a[p[0]];

    bool flag = true;

    for (int i = 1; i < n; i++) {
        int lo = l, hi = r, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (mid - a[p[i]] > pre) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (ans == -1) {
            flag = false;
            break;
        }
        b[p[i]] = ans;
        pre = b[p[i]] - a[p[i]];
    }

    if (!flag) cout << -1 << endl;
    else for (auto x: b) cout << x << ' ';
    cout << endl;

    return 0;
}





