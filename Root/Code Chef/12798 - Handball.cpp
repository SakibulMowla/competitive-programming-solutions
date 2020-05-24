#include "bits/stdc++.h"

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

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (cin >> n >> m) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = 1;
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                if (!v) f = 0;
            }
            if (f) ans++;
        }
        cout << ans << '\n';
    }

    return 0;
}






