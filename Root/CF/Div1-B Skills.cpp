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

pll b_search(int lo, int hi, vector <ll>& need, ll m, vector <pll>& v) {
    pll ans = {0, -1};
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (need[mid] <= m) {
            ans.Y = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (ans.Y != -1) {
        m -= need[ans.Y];
        ans.X = v[ans.Y].X + (m / (ans.Y + 1));
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        ll a, cf, cm, m;
        cin >> a >> cf >> cm >> m;

        vector <pll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].X;
            v[i].Y = i;
        }
        sort(v.begin(), v.end());

        vector <ll> need(n, 0);
        for (int i = 1; i < n; i++) {
            need[i] = need[i-1] + (ll)(i) * (v[i].X - v[i-1].X);
        }

        pll tmp = b_search(0, n - 1, need, m, v);
        tmp.X = min(tmp.X, a);
        ll ans = cm * tmp.X;
        int up = n, down = tmp.Y;
        ll val = tmp.X;

        for (int i = n - 1; i >= 0; i--) {
            m -= (a - v[i].X);
            if (m >= 0) {
                if (i == 0) {
                    if (cf * (ll)(n - i) + cm * a > ans) {
                        ans = cf * (ll)(n - i) + cm * a;
                        up = i;
                        down = 0;
                        val = a;
                    }
                } else {
                    pll tmp = b_search(0, i - 1, need, m, v);
                    tmp.X = min(tmp.X, a);
                    if (cf * (ll)(n - i) + cm * tmp.X > ans) {
                        ans = cf * (ll)(n - i) + cm * tmp.X;
                        up = i;
                        down = tmp.Y;
                        val = tmp.X;
                    }
                }
            }
        }
        val = min(val, a);

        vector <ll> arr(n);
        for (int i = 0; i < n; i++) {
            if (i >= up) {
                arr[v[i].Y] = a;
            } else if (i <= down) {
                arr[v[i].Y] = val;
            } else {
                arr[v[i].Y] = v[i].X;
            }
        }

//        cout << ">> " << "up = " << up << " down = " << down << " val = " << val << endl;

        cout << ans << endl;
        for (auto x: arr) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}





