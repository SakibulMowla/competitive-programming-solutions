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


#define SZ 3010

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    s = "#" + s;

    vector<int> dp(n + 7, 1000000);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        unordered_set<char> ms;
        int cnt = 0;
        for (int j = i; j >= 1; j--) {
            if (isVowel(s[j])) {
                cnt = 0;
                ms.clear();
            } else {
                cnt++;
                ms.insert(s[j]);
            }
            if (cnt > 2 && ms.size() > 1) {
                break;
            }
            dp[i] = min(dp[i], 1 + dp[j - 1]);
        }
    }

    vector<string> ans;

    int pre = dp[n];
    string tmp = "";

    for (int i = n; i >= 0; i--) {
        if (dp[i] == pre - 1) {
            ans.push_back(tmp);
            tmp = "";
            tmp = tmp + s[i];
            pre--;
        } else {
            tmp = s[i] + tmp;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    return 0;
}





