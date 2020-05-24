#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

ll os[SZ];
ll _ws[SZ];
char s[SZ];

int main() {
    freopen("cow.in", "r", stdin);
    freopen("cow.out", "w", stdout);

    int n;
    scanf("%d", &n);
    scanf("%s", s+1);

    ll ans = 0LL;
    for (int i = n; i >= 1; i--) {
        _ws[i] = _ws[i+1];
        os[i] = os[i+1];
        if (s[i] == 'W') {
            _ws[i]++;
        } else if (s[i] == 'O') {
            os[i] += _ws[i] - _ws[n+1];
        } else {
            ans += os[i] - os[n+1];
        }
    }

    printf("%lld\n", ans);

    return 0;
}



/*
CWOW 1
CCOW 2
CCOOWW 8
*/


