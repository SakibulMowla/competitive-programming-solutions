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
    while (cin >> n) {
        vector < vector <int> > a(n + 1, vector <int> (n + 1));
        vector < vector <int> > cnt(n + 1, vector <int> (n + 1, 0));
        vector <int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                if (i != j) {
                    cnt[a[i][j]][i]++;
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            int best = -1, indx;
            for (int j = 1; j <= n; j++) {
                if (cnt[i][j] > best && !ans[j]) {
                    best = cnt[i][j];
                    indx = j;
                }
            }
            ans[indx] = i;
        }

        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}




