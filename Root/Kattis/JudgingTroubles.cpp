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

map <string, pii> mp;
string s[SZ+SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    FAST

    int n;
    cin >> n;

    for (int i = 0; i < n + n; i++) {
        cin >> s[i];
        if (mp.find(s[i]) == mp.end()) {
            mp[s[i]].X = mp[s[i]].Y = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        mp[s[i]].X++;
    }
    for (int i = n; i < n + n; i++) {
        mp[s[i]].Y++;
    }

    int ans = 0;
    for (auto it:mp) {
        ans += min(it.Y.X, it.Y.Y);
    }

    cout << ans << '\n';

    return 0;
}







