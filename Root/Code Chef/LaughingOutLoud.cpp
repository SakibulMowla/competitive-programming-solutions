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

char s[SZ];

ll a[SZ];
ll b[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%s", s+1);
        int len = strlen(s+1);

        mem(a, 0);
        mem(b, 0);

        for (int i = len; i >= 1; i--) {
            if (s[i] == 'L') {
                a[1]++;
                a[i]--;
            }
        }
        for (int i = 1; i <= len; i++) {
            a[i] += a[i-1];
        }

        for (int i = len; i >= 1; i--) {
            if (s[i] == 'O') {
                b[1] += a[i];
                b[i] -= a[i];
            }
        }
        for (int i = 1; i <= len; i++) {
            b[i] += b[i-1];
        }

        ll ans = 0;
        for (int i = 1; i <= len; i++) {
            if (s[i] == 'L') {
                ans += b[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}




