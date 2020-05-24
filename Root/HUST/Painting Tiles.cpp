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

int dp[2][1010];

int solve (int player, int eggs) {
    if (eggs <= 1) {
        return !player;
    } else {
        int &ret = dp[player][eggs];
        if (ret != -1) return ret;

        ret = !player;

        for (int i = 2; i <= 5; i++) if (eggs >= i) {
            if (player) ret = max(ret, solve(player^1, eggs - i));
            else ret = min(ret, solve(player^1, eggs - i));
        }

        return ret;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);


    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        ll n;
        scanf("%lld", &n);

        cout << "Case " << cs + 1 << ": ";

        if (n == 0 || n == 1 || (n % 7LL == 0) || ((n - 1) % 7LL) == 0) puts("Oh no, my eggs! :(");
        else puts("No eggs for you! :D");
    }

    return 0;
}





