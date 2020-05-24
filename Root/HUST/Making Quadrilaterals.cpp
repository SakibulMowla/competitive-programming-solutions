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

    vector <ll> f(65);
    f[1] = f[2] = f[3] = 1;
    for (int i = 4; i <= 60; i++) {
        f[i] = f[i-1] + f[i-2] + f[i-3];
    }

    int n, cs = 0;
    while (cin >> n && n) {
        cout << "Case " << ++cs << ": " << f[n] << endl;
    }

    return 0;
}







