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

#define SZ 100010

ll a[SZ];
multiset <ll> ms;
set <ll> ss;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        ll m;
        scanf("%d %lld", &n, &m);

        clr(ms);
        clr(ss);

        for (int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
            a[i] %= m;
            if (i) a[i] = (a[i] + a[i-1]) % m;
            ms.insert(a[i]);
            ss.insert(a[i]);
        }

        ll ans = max(*ms.begin(), *prev(ms.end()));

        set <ll> :: iterator it11 = ss.begin();
        set <ll> :: iterator it12 = prev(ss.end());
        ans = max(ans, (*next(it11) + m) % m);
        ans = max(ans, (*prev(it12) + m) % m);

        for (int i = 0; i < n - 1; i++) {
            ms.erase(ms.find(a[i]));
            if (ms.find(a[i]) == ms.end()) ss.erase(ss.find(a[i]));

            set <ll> :: iterator it1 = ss.begin();
            set <ll> :: iterator it2 = prev(ss.end());

            ll x = (*it1 - a[i] + m) % m;
            ll y = (*it2 - a[i] + m) % m;

//            printf("a[i] = %lld it1 = %lld it2 = %lld\n", a[i], *it1, *it2);

            ans = max(ans, max(x, y));

            if (n - i - 1 > 2) {
                ans = max(ans, (*next(it1) - a[i] + m) % m);
                ans = max(ans, (*prev(it2) - a[i] + m) % m);
            }
        }

        printf("%lld\n", ans);
    }


    return 0;
}

/*
4 6
4 3 2 1
*/




