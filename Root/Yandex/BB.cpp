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

string s;
int x, y;
int len;
int dp[SZ][2][2];

int solve (int indx, int flag, int fbd) {
    if (indx == len) return 0;
    int &ret = dp[indx][flag][fbd];
    if (ret != -1) return ret;
    ret = 0;
    if (flag == 1) {
        if (!fbd && s[indx] - '0' == x) ret = 1 + solve(indx + 1, flag, 0);
        else if (!fbd && s[indx] - '0' > x) ret = max(ret, 1 + solve(indx + 1, 0, 0));
        if (s[indx] - '0' == y) ret = max(ret, 1 + solve(indx + 1, flag, 0));
        else if (s[indx] - '0' > y) ret = max(ret, 1 + solve(indx + 1, 0, 0));
    } else {
        ret = max(ret, 1 + solve(indx + 1, flag, 0));
    }
    return ret;
}

string path (int indx, int flag, int fbd) {
    if (indx == len) return "";
    int ret1 = 0, ret2 = 0;
    string num = "";
    if (flag == 1) {
        if (!fbd && s[indx] - '0' == x) ret1 = 1 + solve(indx + 1, flag, 0);
        else if (!fbd && s[indx] - '0' > x) ret1 = max(ret1, 1 + solve(indx + 1, 0, 0));
        if (s[indx] - '0' == y) ret2 = max(ret2, 1 + solve(indx + 1, flag, 0));
        else if (s[indx] - '0' > y) ret2 = max(ret2, 1 + solve(indx + 1, 0, 0));
        if ((ret1 == ret2 || ret2 > ret1) && (ret1 + ret2)) {
            if (s[indx] - '0' == y) num = (char)(y + '0') + path(indx + 1, flag, 0);
            else if (s[indx] - '0' > y) num = (char)(y + '0') + path(indx + 1, 0, 0);
        }
        if (ret1 > ret2) {
            if (s[indx] - '0' == x) num = (char)(x + '0') + path(indx + 1, flag, 0);
            else if (s[indx] - '0' > x) num = (char)(x + '0') + path(indx + 1, 0, 0);
        }
    } else {
        num = (char)(y + '0') + path(indx + 1, flag, 0);
    }
    return num;
}

string doit (int indx, int flag, int isFirst) {
    if (indx == len) return "";
    string num = "";
    if (flag == 0) {
        num = (char)(y + '0') + doit(indx + 1, 0, 0);
    } else {
        if (y < s[indx] - '0') num = (char)(y + '0') + doit(indx + 1, 0, 0);
        else if (y == s[indx] - '0') num = (char)(y + '0') + doit(indx + 1, flag, 0);
        else if (!isFirst && x < s[indx] - '0') num = (char)(x + '0') + doit(indx + 1, 0, 0);
        else if (!isFirst && x == s[indx] - '0') num = (char)(x + '0') + doit(indx + 1, flag, 0);
        else num = doit(indx + 1, 0, isFirst);
    }
    return num;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    cin >> s >> x >> y;

    while (sz(s) && s[0] == '0') s.erase(s.begin());

    len = sz(s);

    mem(dp, -1);
    solve(0, 1, x == 0);
//    string ans = path(0, 1, x == 0);
    string ans = doit(0, 1, x == 0);
    if (ans == "") {
        cout << -1 << endl;
    }
    else cout << ans << endl;

    return 0;
}




