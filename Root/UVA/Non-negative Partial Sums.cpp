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

#define SZ  1000010

int a[SZ];
int formn[SZ];
int bckmn[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;

    while(scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 1; i <= n; i++) {
            a[i] += a[i-1];
        }

        formn[1] = a[1];
        for (int i = 2; i <= n; i++) {
            formn[i] = min(formn[i-1], a[i]);
        }

        bckmn[n] = a[n];
        for (int i = n - 1; i >= 1; i--) {
            bckmn[i] = min(bckmn[i+1], a[i]);
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (bckmn[i] >= a[i-1] && formn[i-1] + a[n] >= a[i-1])
                ans++;
        }

        printf("%d\n", ans);
    }


    return 0;
}






