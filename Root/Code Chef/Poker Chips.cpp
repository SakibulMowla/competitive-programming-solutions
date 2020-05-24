#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        vector <int> a(n);
        int sum = 0;

        for (auto &x: a) {
            cin >> x;
            sum += x;
        }

        if ((sum - (n * (n - 1) / 2)) % n == 0 && (sum - (n * (n - 1) / 2)) / n >= 0) {
            int x = (sum - (n * (n - 1) / 2)) / n;
            int ans = 0;

//            cout << ">> x =  " << x << endl;

            for (int i = 0; i < n; i++) {
                ans += abs(x + i - a[i]);
            }
            cout << ans / 2 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}




