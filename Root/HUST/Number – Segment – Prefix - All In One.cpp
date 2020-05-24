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

//    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll lo, hi;
        scanf("%lld %lld", &lo, &hi);

        int q;
        scanf("%d", &q);

        while (q--) {
            ll n;
            scanf("%lld", &n);

            if (n >= lo && n <= hi) {
                printf("1\n");
            } else {
                int ans = 0;
                ll HII;
                for (n = n * 10LL, HII = 9; n <= 2000000000LL; n *= 10LL, HII = HII * 10LL + 9LL) {
                    ll LO = 0;
                    ll HI = HII;
                    while (LO <= HI) {
                        ll mid = (LO + HI) / 2LL;
                        if (n + mid >= lo && n + mid <= hi) {
                            ans = 1;
                            goto HELL;
                        } else if (n + mid < lo) {
                            LO = mid + 1;
                        } else if (n + mid > hi) {
                            HI = mid - 1;
                        }
                    }
                }
                HELL:;
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}





