#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
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
        int n;
        cin >> n;

        vector <int> s;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            int lo = 0;
            int hi = sz(s) - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = (lo + hi) >> 1;
                if (s[mid] > x) {
                    hi = mid - 1;
                    ans = mid;
                } else {
                    lo = mid + 1;
                }
            }

//            cout << ">> " << i << ' ' << ans << endl;

            if (ans == -1) s.pb(x);
            else s[ans] = x;
        }

        cout << sz(s);
        for (int i = 0; i < sz(s); i++) {
            cout << ' ' << s[i];
        }
        cout << endl;
    }

    return 0;
}




