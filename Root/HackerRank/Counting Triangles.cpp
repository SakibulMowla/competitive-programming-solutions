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

struct Triangle {
    int n;
    vector <int> a;
    vector <bool> mark;

    Triangle (int n) : n(n), a(n), mark(10000+10, false) {
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mark[a[i]] = true;
        }
        cout << Acute() << ' ' << Right() << ' ' << Obtuse() << endl;
    }

    int Right () {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int now = a[i] * a[i] + a[j] * a[j];
                int root = (int)sqrt((double)now);
                if (root > 10000) {
                    break;
                } else if (root * root == now && mark[root] == true) {
                    ans++;
                }
            }
        }
        return ans;
    }

    ll Obtuse () {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = i;
            for (int k = i + 2; k < n; k++) {
                while (a[i] + a[lo] <= a[k] && lo < k) {
                    lo++;
                }
                while (hi + 1 < k  && a[i] * a[i] + a[hi + 1] * a[hi + 1] < a[k] * a[k]) {
                    hi++;
                }
                if (hi >= lo) {
                    ans += (ll)(hi - lo + 1);
                }
            }
        }
        return ans;
    }

    ll Acute () {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int hi = i + 1;
            for (int k = i + 2; k < n; k++) {
                while (hi < k  && a[i] * a[i] + a[hi] * a[hi] <= a[k] * a[k]) {
                    hi++;
                }
                ans += (ll)(k - hi);
            }
        }
        return ans;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    Triangle Task(n);

    return 0;
}



