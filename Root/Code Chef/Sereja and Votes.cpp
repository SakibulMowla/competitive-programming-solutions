#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
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

int b[10002];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        int lo = 0, hi = 0;
        bool flag = false;

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            hi += b[i];
            if (b[i]) {
                lo += b[i] - 1;
                flag = true;
            }
        }
        if (flag) {
            lo++;
        }

        if (lo <= 100 && hi >= 100) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}




