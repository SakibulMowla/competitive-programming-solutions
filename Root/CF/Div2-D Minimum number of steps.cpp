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
const ll mod = 1E9 + 7;


#define SZ 1000010

char s[SZ];
ll two[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);

    two[0] = 1;
    for (int i = 1; i < SZ; i++) two[i] = (2 * two[i - 1]) % mod;

    scanf("%s", s);
    int n = strlen(s);

    ll cnta = 0;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cnta++;
        else if (cnta != 0) {
            ll cntb = 0;
            while (i + cntb < n && s[i + cntb] == 'b') cntb++;
            ans = ans + (cntb * (two[cnta] - 1)) % mod;
            if (ans >= mod) ans -= mod;
            i += cntb - 1;
        }
    }

    printf("%I64d\n", ans);

    return 0;
}





