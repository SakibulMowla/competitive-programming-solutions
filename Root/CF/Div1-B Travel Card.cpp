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

int a[SZ];
int dp[SZ];

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i] = 20 + dp[i-1];
        for (int j = i - 1; j >= 1; j--) {
            int range = a[i] - a[j] + 1;
            if (range <= 90) dp[i] = min(dp[i], dp[j - 1] + 50);
            else if (range <= 1440) dp[i] = min(dp[i], dp[j - 1] + 120);
            else break;
        }
    }

    printf("%d\n", dp[1]);
    for (int i = 2; i <= n; i++) {
        if (dp[i] >= dp[i - 1]) printf("%d\n", dp[i] - dp[i-1]);
        else printf("0\n");
    }

    return 0;
}





