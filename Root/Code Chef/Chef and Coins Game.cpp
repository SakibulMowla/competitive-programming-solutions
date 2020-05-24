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

int dp[110];
vector <int> prime;

int solve (int n) {
    if (n == 0) return 0;
    int &ret = dp[n];
    if (ret != -1) return ret;

    ret = !solve(n - 1);
    for (int i = 0; i < 25; i++) {
        for (int j = prime[i]; j <= n; j *= prime[i]) {
            ret = max(ret, (int)(!solve(n - j)));
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

    /*mem(dp, -1);

    for (int i = 2; i <= 100; i++) {
        bool f = true;
        for (int j = 2; j < i; j++) {
            if (i %j == 0) {
                f = false;
                j = i;
            }
        }
        if (f) prime.pb(i);
    }

    cout << sz(prime) << endl;

    for (int i = 1; i <= 100; i++) {
        if (!solve(i)) {
            cout << i << endl;
        }
    }*/

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        cout << ((n % 6)? "Chef": "Misha") << endl;
    }

    return 0;
}





