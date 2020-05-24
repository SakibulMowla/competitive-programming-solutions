#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010

double a[1010];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, l;

    while(cin >> n >> l) {
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a+1, a+n+1);
        double d = max(a[1], ((double)l - a[n]));

        for (int i = 1; i <= n-1; i++)
            d = max(d, (a[i+1] - a[i]) / 2.0);

        cout << fixed;
        cout << setprecision(12) << d << '\n';
    }

    return 0;
}







