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

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'X') {
                continue;
            }
            int j = i;
            while (j + 1 < sz(s) && s[j+1] == s[j]) {
                j++;
            }
            ans += (j - i + 1) * (j - i + 2) / 2;
            i = j;
        }

        cout << ans << '\n';
    }

    return 0;
}




