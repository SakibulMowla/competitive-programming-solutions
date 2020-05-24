#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 2050

int n, m;
int a[SZ];
int tmp[SZ];
bool found;

void bctk(int pos, int lft, int sum) {
    if (found) return;
    if (!lft) {
        if (sum % n == 0) {
            found = true;
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                if (i) cout << ' ';
                cout << tmp[i];
            }
            cout << endl;
        }
        return;
    }
    if (pos == m) return;

    tmp[n-lft] = a[pos];
    bctk(pos + 1, lft - 1, sum + a[pos]);
    bctk(pos + 1, lft, sum);

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    while (cin >> n && n) {
        m = 2 * n - 1;
        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        found = false;
        bctk(0, n, 0);
        if (!found) cout << "No" << endl;
    }


    return 0;
}







