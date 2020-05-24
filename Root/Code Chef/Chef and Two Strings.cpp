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

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s1, s2;
        cin >> s1 >> s2;

        int ans = 0, potential = 0;
        for (int i = 0; i < sz(s1); i++) {
            if (s1[i] == '?' || s2[i] == '?') potential++;
            else if (s1[i] != s2[i]) ans++;
        }

        cout << ans << ' ' << ans + potential << endl;
    }

    return 0;
}





