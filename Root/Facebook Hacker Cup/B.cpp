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
//#if defined JESI
//        freopen("lazy_loading.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
//#endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <int> v(n);
        for (auto &x: v) {
            cin >> x;
        }

        sort(v.begin(), v.end());

        deque <int> dq;
        for (auto x: v) {
            dq.push_back(x);
        }

        int ans = 0;
        while (!dq.empty()) {
            int best = dq.back(); dq.pop_back();
            int sum = best;
            while (sum < 50 && !dq.empty()) {
                sum += best;
                dq.pop_front();
            }
            if (sum >= 50) {
                ans++;
            }
        }

        cout << "Case #" << cs + 1 << ": " << ans << endl;
    }

    return 0;
}




