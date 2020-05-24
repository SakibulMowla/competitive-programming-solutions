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
const ll mod = 1E9;

#define SZ 500000 + 10

ll a[SZ];
ll b[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    FAST


    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort (a+1, a+n+1);

    for (int i = 1; i <= n; i++) {
        b[i] = a[i] + b[i-1];
    }

    int qq;
    scanf("%d", &qq);

    ll now = 0;

    for (int i = 0; i < qq; i++) {
        ll x;
        scanf("%lld", &x);
        now += x;

        int lo = 1;
        int hi = n;
        int ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (a[mid] + now < 0) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        ll res = (b[n] - b[ans] + now * (ll)(n-ans)) - (b[ans] + now * (ll)ans);
        printf("%lld\n", res);
    }



    return 0;
}







