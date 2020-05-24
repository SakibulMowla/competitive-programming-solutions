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

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector < vector <int> > cnt(30, vector <int> (n + 2, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) cnt[j][i + 1] = cnt[j][i];
        cnt[s[i] - 'a'][i + 1] += 1;
    }

    vector < vector <int> > dp(30, vector <int> (n + 2, 00000000));

    for (int i = 0; i < 26; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                int cal = (k - j + 1) - (cnt[i][k] - cnt[i][j - 1]);
                dp[i][cal] = max(dp[i][cal], k - j + 1);
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        if (m + cnt[c - 'a'][n] >= n) cout << n << endl;
        else cout << dp[c - 'a'][m] << endl;
    }

    return 0;
}




