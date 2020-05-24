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


#define SZ 10010

int n;
string s;
vector <int> a;

struct data {
    int p, q, r;
    data() {}
    data (int a, int b, int c) {
        p = a, q = b, r = c;
    }
};

data dp[SZ];
bool col[SZ];
data base;

data solve (int indx) {
    if (indx == -1) return base;
    data &ret = dp[indx];
    if (col[indx]) return ret;
    col[indx] = true;

    ret.p = 0;
    ret.q = 0;
    ret.r = 100000;

    for (int i = indx; i >= 0; i--) {
        bool ok = true;
        for (int j = indx; j >= i; j--) {
            if (a[s[j] - 'a'] < indx - i + 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            data tmp = solve(i - 1);
            ret.p = (ret.p + tmp.p) % mod;
            ret.q = max(ret.q, max(tmp.q, indx - i + 1));
            ret.r = min(1 + tmp.r, ret.r);
        } else {
            break;
        }
    }

    return ret;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; i < 26; i++) {
        int c;
        cin >> c;
        a.pb(c);
    }

    base.p = 1;
    base.q = 0;
    base.r = 0;
    mem(col, false);
    data ans = solve(n - 1);

    cout << ans.p << endl;
    cout << ans.q << endl;
    cout << ans.r << endl;

    return 0;
}





