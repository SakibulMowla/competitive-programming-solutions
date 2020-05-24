#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

int solve (vector <int> &v, int x, int n) {
    int sum = 0, ans = -1;
    for (int i = 0, r = 0; i < n; i++) {
        if (i == r) {
            sum += (ll)v[r++];
        }
        while (sum < x && r < n) {
            sum += (ll)v[r++];
        }
        if (sum >= x) {
            ans = (ans == -1 ) ? r - i : min(ans, r - i);
        }
        sum -= (ll)v[i];
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, x;
        cin >> n >> x;

        vector <int> v(n);
        int flag = false;

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (v[i] >= 0) {
                flag = true;
            }
        }

        if (x == 0) {
            if (flag) cout << 1 << endl;
            else cout << -1 << endl;
        } else if (x > 0) {
            cout << solve(v, x, n) << endl;
        } else if (x < 0) {
            for (int i = 0; i < n; i++) {
                v[i] += (-x);
            }
            x = 0;
            cout << solve(v, x, n) << endl;
        }
    }


    return 0;
}







