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
const ll mod = 1E9 + 7;


#define SZ 10000010

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <int> X(n), W(n);

    for (auto &x: X) cin >> x;

    int num = 0, denum = 0;
    for (int i = 0; i < n; i++) {
        cin >> W[i];
        num += X[i] * W[i];
        denum += W[i];
    }

    cout << fixed << setprecision(1) << 1.0 * num / denum << endl;

    return 0;
}




