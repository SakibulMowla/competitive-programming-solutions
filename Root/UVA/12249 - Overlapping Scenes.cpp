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

#define SZ 100010

int solve (vector <string> &v) {
    string s = v[0];
    for (int i = 1; i < sz(v); i++) {
        int tmp = 0;
        for (int k = sz(s) - 1; k >= 0; k--) {
            int j;
            for (j = 0; j < sz(v[i]) && k+j < sz(s); j++) {
                if (v[i][j] != s[k+j]) {
                    break;
                }
            }
            if (k + j == sz(s)) tmp = max(tmp, j);
        }
        for (int j = tmp; j < sz(v[i]); j++) {
            s += v[i][j];
        }
    }
    return sz(s);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int ans = numeric_limits<int>::max();

        do {
            ans = min(ans, solve(v));
        } while(next_permutation(v.begin(), v.end()));

        cout << "Case " << cs + 1 << ": " << ans << endl;
    }


    return 0;
}








