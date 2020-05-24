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
//    #if defined JESI
//        freopen("easy.in", "r", stdin);
//        freopen("easy.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector < vector <int> > plist(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            plist[i].pb(y);
        }
    }

    int sum = 0, cnt = 0;
    for (int i = 0; cnt < k; i++) {
        if (i == n) i = 0;
        int now;
        if (sz(plist[i]) == 0) {
            now = 50;
        } else {
            now = plist[i][0];
            plist[i].erase(plist[i].begin() + 0);
        }
        if (now >= sum) {
            sum += now;
            cnt++;
        }
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (sz(plist[i]) != 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            break;
        }
    }
    sum += 50 * (k - cnt);
    cout << sum << endl;

    return 0;
}





