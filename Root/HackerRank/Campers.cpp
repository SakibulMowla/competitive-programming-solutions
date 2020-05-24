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

#define SZ 2000010

int col[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        col[x] = 1;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!col[i-1] && !col[i+1]) {
            col[i] = 1;
            ans++;
        }
    }

    cout << ans << endl;


    return 0;
}







