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

#define SZ 200010

int a[SZ];
map <int, int> mp;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n;
    cin >> n;

    int Same = 0;

    for (int i = 0; i < n + n; i++) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end()) mp[ a[i] ] = 0;
        mp[a[i]]++;
        if (i >= n && a[i] == a[i-n]) Same++;
    }

    ll m;
    cin >> m;

    ll ans = 1;

    for (auto &it: mp) {
        for (int i = 1; i <= it.Y; i++) {
            int j = i;
            while (Same && j % 2 == 0) {
                Same--;
                j /= 2;
            }
            ans = (ans * (ll)j) % m;
        }
    }

    cout << ans << '\n';


    return 0;
}







