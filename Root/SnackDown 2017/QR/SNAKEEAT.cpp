#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, q;
        cin >> n >> q;

        vector <int> a(n);
        for (auto &x: a) cin >> x;

        sort(a.begin(), a.end());

        vector <ll> sum(n, 0);
        sum[0] = a[0];
        for (int i = 1; i < n; i++) sum[i] += sum[i - 1] + a[i];

        while (q--) {
            ll x;
            cin >> x;

            int lo = 0, hi = n - 1, lim = n;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (a[mid] >= x) {
                    lim = mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            lo = 1, hi = lim - 1;
            int ans = 0;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                ll food = x * (lim - mid) - sum[lim - 1] + sum[mid - 1];
                if (mid >= food) {
                    ans = lim - mid;
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }

            cout << n - lim + ans << endl;
        }
    }

    return 0;
}


