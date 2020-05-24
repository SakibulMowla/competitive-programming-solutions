#include <bits/stdc++.h>

using namespace std;

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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int tmp = 0;
            for (int k = 0; k < n; k++) {
                if ((a[k].X - a[i].X) * (a[i].Y - a[j].Y) == (a[i].X - a[j].X) * (a[k].Y - a[i].Y)) {
                    tmp++;
                }
            }
            ans = max(ans, tmp);
        }
    }

    cout << ans << endl;

    return 0;
}


