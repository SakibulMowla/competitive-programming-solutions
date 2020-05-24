#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    while(t--) {
        ll a, b;
        scanf("%lld %lld", &a, &b);

        ll ans = 0LL;
        bool f = 0;

        for (ll i = 32; i >= 0; i--) {
            if (b & (1LL<<i))
                f = 1;
            if (f) {
                if ( (a & (1LL<<i) ) == 0 && ( (b & (1LL<<i)) != 0 ))
                    break;
//                printf("i = %lld\n", i);
                if ( (a & (1LL<<i) ) == 0 && ( (b & (1LL<<i)) == 0 ))
                    continue;
                ans |= (1LL<<i);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}






