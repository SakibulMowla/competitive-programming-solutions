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

int a[SZ];

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        ll ans = 0LL;
        stack <int> stk;
        stk.push(0);

        for (int i = 1; i <= n; i++) {
            ll tmp;
            while (a[stk.top()] > a[i] && stk.top()) {
                tmp = a[stk.top()];
                stk.pop();
                tmp *= (ll)(i - stk.top() - 1);
                ans = max(ans, tmp);
            }
            stk.push(i);
        }

        while (stk.top()) {
            ll tmp = a[stk.top()];
            stk.pop();
            tmp *= (ll)(n - stk.top());
            ans = max(ans, tmp);
        }

        printf("%lld\n", ans);
    }


    return 0;
}







