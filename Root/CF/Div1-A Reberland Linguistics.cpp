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


#define SZ 10010

int vis[SZ][4];
string a;
int n;
set <string> ms;

int bctk (int pos, int len) {
    int &ret = vis[pos][len];

    if (ret != -1) {
        return ret;
    }

    ret = 0;

    if (pos == n) {
        ret = 1;
    } else if (n - pos > 1) {
        string prev = "";
        for (int i = len; i > 0; i--) {
            prev = prev + a[pos - i];
        }

        string now = "";
        for (int i = 0; i < 3 && pos + i < n; i++) {
            now = now + a[pos + i];
            if (i > 0) {
                if (prev != now) {
                    ret = max(ret, bctk(pos + i + 1, i + 1));
                }
            }
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

    cin >> a;
    n = sz(a);
    mem(vis, -1);

    for (int i = 5; i < n; i++) {
        bctk(i, 0);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 2; j < 4; j++) {
            if (vis[i][j] == 1) {
                string tmp = "";
                for (int k = j; k > 0; k--) {
                    tmp += a[i - k];
                }
                ms.insert(tmp);
            }
        }
    }

    cout << sz(ms) << endl;
    for (auto it: ms) {
        cout << it << endl;
    }

    return 0;
}





