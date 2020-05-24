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
using plli = pair <pll, int>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <plli> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].X.X >> v[i].X.Y;
        v[i].Y = i + 1;
    }

    sort(v.begin(), v.end());

    set <int> points;
    set <pii> last;
    ll ans = 0;

    for (int i = 0; i < k; i++) {
        points.insert(v[i].Y);
        last.insert({v[i].X.Y, v[i].Y});
    }

    ans = max(ans, (*last.begin()).X - v[k-1].X.X + 1);
    vector <int> v1, v2;

    for (int i = k; i < n; i++) {
        pii tmp = (*last.begin());
        if (tmp.X < v[i].X.Y) {
            last.erase(tmp);
            last.insert({v[i].X.Y, v[i].Y});
            v1.pb(tmp.Y);
            v2.pb(v[i].Y);
            int now = (*last.begin()).X - v[i].X.X + 1;
            if (now > ans) {
                ans = now;
                for (int i = 0; i < sz(v1); i++) {
                    points.erase(v1[i]);
                    points.insert(v2[i]);
                }
                clr(v1);
                clr(v2);
            }
        }
    }

    cout << ans << endl;
    for (auto x: points) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}




