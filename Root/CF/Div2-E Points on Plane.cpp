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

    int n;
    scanf("%d", &n);

    vector <pii> pnts[1010];

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        pnts[x/1000].pb({y, i + 1});
    }

    for (int i = 0, now = 0; i <= 1000; i++) {
        if (sz(pnts[i])) {
            sort(pnts[i].begin(), pnts[i].end());
            int k = sz(pnts[i]);
            if (!now) {
                for (int j = 0; j < k; j++) {
                    printf("%d ", pnts[i][j].Y);
                }
            } else {
                for (int j = k - 1; j >= 0; j--) {
                    printf("%d ", pnts[i][j].Y);
                }
            }
            now ^= 1;
        }
    }
    printf("\n");

    return 0;
}





