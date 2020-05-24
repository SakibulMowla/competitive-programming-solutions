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


#define SZ 200010



int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> p(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }

    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        tot += b[i];
    }

    int ans = 0;
    if (n == 1) {
        ans = (b[0] == 0);
    } else if (n == 2) {
        if (p[0] == 0 && p[1] == 1) ans = 2;
        ans += (tot % 2 == 0);
    } else {
        vector <bool> col(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++) if (!col[i]) {
            col[i] = true;
            int j = i;
            while (!col[p[j]]) {
                col[p[j]] = true;
                j = p[j];
            }
            cnt++;
        }
        if (cnt > 1) ans = cnt;
        ans += (tot % 2 == 0);
    }

    cout << ans << endl;

    return 0;
}





