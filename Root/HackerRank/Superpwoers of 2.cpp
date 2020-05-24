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

ll a, b;

ll bigmod (int p) {
    if (p == 0) return (2LL%b);
    if (p == 1) return (4LL%b);
    ll x = bigmod(p/2);
    x = (x * x) % b;
    if (p&1) x = (x * 4LL) % b;
    return x;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    scanf("%d %d", &a, &b);
    printf("%lld\n", bigmod(a));

    return 0;
}






