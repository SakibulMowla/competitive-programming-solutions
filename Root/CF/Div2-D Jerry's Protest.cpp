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


#define SZ 5010

ll dp[4][3*SZ];
int dif[SZ];

ll solve (int step, int sum) {
    if (step == 3) {
        return (sum < 0);
    } else {
        ll &ret = dp[step][sum];
        if (ret != -1) return ret;

        ret = 0;
        for (int i = 1; i <= 5000; i++) {
            if (dif[i]) ret += (ll)dif[i] * solve(step + 1, (step <= 1)? sum + i: sum - i);
        }

        return ret;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    while (cin >> n) {
        vector <int> a(n);
        for (int &x: a) {
            cin >> x;
        }

        mem(dif, 0);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dif[abs(a[i]-a[j])]++;
            }
        }

        mem(dp, -1);
        double num = solve(0, 0);
        double dnum = (n * (n - 1)) / 2;

        cout << fixed << setprecision(12) << num / dnum / dnum / dnum << endl;
    }

    return 0;
}





