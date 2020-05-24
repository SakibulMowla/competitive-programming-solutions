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
const ll mod = 1E9;

#define SZ 100010



int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif


    FAST

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        unordered_map <int, int> mp;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
//            cout << it->first << ' ' << it->second << '\n';
            ans = max(ans, it->second);
        }

        cout << n - ans << '\n';
    }

    return 0;
}







