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

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

//    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = sz(s);

    vector < vector <bool> > isPalin(n, vector <bool> (n));
    vector < vector <int> > dp(n, vector <int> (n));

    for (int i = 0; i < n; i++) {
        isPalin[i][i] = true;
        dp[i][i] = 1;
    }

    for (int i = 0; i + 1 < n; i++) {
        isPalin[i][i+1] = (s[i] == s[i + 1]);
        dp[i][i + 1] = 2 + (s[i] == s[i + 1]);
    }

    for (int len = 3; len <= n; len++) {
        for (int start = 0; start + len - 1 < n; start++) {
            isPalin[start][start + len - 1] = ((s[start] == s[start + len - 1]) && isPalin[start + 1][start + len - 2]);
            dp[start][start + len - 1] = dp[start + 1][start + len - 1] + dp[start][start + len - 2] - dp[start + 1][start + len - 2] + isPalin[start][start + len - 1];
        }
    }

    int q;
    scanf("%d", &q);

    for (int cs = 0; cs < q; cs++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", dp[a-1][b-1]);
    }

    return 0;
}





