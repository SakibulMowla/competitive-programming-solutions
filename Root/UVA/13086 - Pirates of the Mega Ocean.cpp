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

int mark[SZ];
ll a[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++) {
        ll n, m;
        scanf("%lld %lld", &n, &m);

        ll P, Q, R, X, Y, Z;
        scanf("%lld %lld %lld %lld %lld %lld", &P, &Q, &R, &X, &Y, &Z);

        ll sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += (a[i] = (P * i * i + Q * i + R) % 1000007);
        }

        for (int i = 1; i <= m; i++) {
            mark[(X * i * i + Y * i + Z) % n + 1] = cs;
        }

        ll mn = numeric_limits <ll> :: max();

        for (int i = 1; i <= n; i++) {
            if (mark[i] != cs) {
                mn = min(mn, a[i]);
            }
        }

        printf("Case %d: %lld\n", cs, (sum - mn) * mn);
    }


    return 0;
}





