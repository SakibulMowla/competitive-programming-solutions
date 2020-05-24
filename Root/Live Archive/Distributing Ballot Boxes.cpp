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

#define SZ  500010

int a[SZ];

inline bool ok (int &mid, int &n, int &box) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (a[i] / mid) + (a[i] % mid != 0);
        if (sum > box)
            return false;
    }
    return true;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, box;

    while (scanf("%d %d", &n, &box) == 2) {
        if (n == -1 && box == -1) break;

        int hi = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (a[i] > hi) {
                hi = a[i];
            }
        }

        int lo = 1, ans = 0;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (ok(mid, n, box)) {
                ans = mid;
                hi = mid - 1;
            } else lo = mid + 1;
        }

        assert(ans!=0);

        printf("%d\n", ans);
    }


    return 0;
}





