#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    vector <pii> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].X >> a[i].Y;
    }

    int zx = 1, zy = 1;

    for (int i = 1; i < n; i++) {
        if (a[i].X == a[0].X) zx++;
    }

    for (int i = 1; i < n; i++) {
        if (a[i].Y == a[0].Y) zy++;
    }

    cout << ((zx == n || zy == n)? "YES": "NO") << endl;

    return 0;
}



