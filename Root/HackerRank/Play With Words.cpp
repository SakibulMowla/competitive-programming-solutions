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

#define SZ 3010

char s[SZ];
int dp[SZ][SZ];

int solve (int i, int j) {
    if (i == j) return 1;
    if (i + 1 == j) return (s[i] == s[j] ? 2 : 1);
    int &ret = dp[i][j];
    if (ret != -1) return ret;
    ret = max(solve(i+1, j), solve(i, j-1));
    if (s[i] == s[j]) ret = 2 + solve(i+1, j-1);
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    scanf("%s", s);
    int len = strlen(s);

    if (len == 1) {
        printf("0\n");
    } else {
        int ans = 0;
        mem(dp, -1);
        for (int i = 0; i < len-1; i++) {
            ans = max(ans, solve(0, i) * solve(i+1, len-1));
//            printf("%d %d %d\n", i, solve(0, i), solve(i+1, len-1));
        }
        printf("%d\n", ans);
    }

    return 0;
}






