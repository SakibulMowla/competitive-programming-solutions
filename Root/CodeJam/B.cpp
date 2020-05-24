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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector<int> cnt(n, 0);
        vector<bool> sold(n, false);

        for (int i = 0; i < n; i++) {
            int d;
            cin >> d;

            vector<int> a(d);
            for (auto& x: a) {
                cin >> x;
                cnt[x]++;
            }

            random_shuffle(a.begin(), a.end());

            int ans = -1, best = n + 100;
            for (int j = 0; j < d; j++) {
                if (sold[a[j]] == false && cnt[a[j]] < best) {
                    best = cnt[a[j]];
                    ans = a[j];
                }
            }

            if (ans != -1) sold[ans] = true;
            cout << ans << endl;
        }
    }

    return 0;
}






