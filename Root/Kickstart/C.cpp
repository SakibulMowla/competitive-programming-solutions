#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1E9 + 7;

#define SZ  410
#define SZ1  22
#define SZ2  4010


int main() {
    #if defined JESI
//        freopen("C-large-practice.in", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int v, s;
        cin >> v >> s;

        vector <string> words(v);
        vector <int> len(v);
        vector < vector <int> > cnt(v, vector <int> (26, 0));

        for (int i = 0; i < v; i++) {
            cin >> words[i];
            len[i] = words[i].size();
            for (int j = 0; j < len[i]; j++) {
                cnt[i][words[i][j]-'a']++;
            }
        }

        cout << "Case #" << cs + 1 << ":";

        for (int i = 0; i < s; i++) {
            string a;
            cin >> a;

            vector < vector <bool> > jump(402, vector <bool> (SZ2, false));
            int n = a.size();
            vector < vector <int> > sum(n + 2, vector <int> (26, 0));

            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 26; k++) {
                    sum[j + 1][k] = sum[j][k];
                }
                sum[j + 1][a[j] - 'a']++;
            }

            for (int j = 0; j < v; j++) {
                for (int k = len[j]; k <= n; k++) {
                    bool flag = true;
                    for (int l = 0; l < 26; l++) {
                        if (cnt[j][l] != sum[k][l] - sum[k - len[j]][l]) {
                            flag = false;
                            break;
                        }
                    }
                    jump[j][k] = flag;
                }
            }

            vector <ll> dp(n + 2, 0);
            dp[0] = 1;

            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < v; k++) {
                    if (jump[k][j] == true) {
                        dp[j] = dp[j] + dp[j - len[k]];
                        if (dp[j] >= mod) {
                            dp[j] -= mod;
                        }
                    }
                }
            }

            cout << ' ' << dp[n];
        }

        cout << endl;
    }

    return 0;
}

