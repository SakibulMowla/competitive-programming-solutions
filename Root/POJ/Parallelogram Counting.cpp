#include <iostream>
#include <algorithm>

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

#define SZ 1010

pii a[SZ];
pii b[SZ*SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (register int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        for (register int i = 0; i < n; i++) {
            cin >> a[i].X >> a[i].Y;
        }

        int k = 0;
        for (register int i = 0; i < n; i++) {
            for (register int j = 0; j < i; j++) {
                b[k].X = a[i].X + a[j].X;
                b[k++].Y = a[i].Y + a[j].Y;
            }
        }

        sort(b, b + k);

        ll ans = 0;
        int cnt = 1;

        for (register int i = 1; i < k; i++) {
            if (b[i].X == b[i-1].X && b[i].Y == b[i-1].Y) {
                cnt++;
            } else {
                ans += (ll)cnt * (ll)(cnt-1) / 2LL;
                cnt = 1;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}




