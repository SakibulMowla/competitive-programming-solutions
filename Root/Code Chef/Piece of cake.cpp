#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;
        map <char, int> mp;
        for (int i = 0; i < sz(s); i++) {
            mp[s[i]]++;
        }
        int sum = 0, mx = 0;
        for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            sum += it->second;
            mx = max(mx, it->second);
        }
        bool flag = (sz(mp) > 1 && mx == (sum - mx));
        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}




