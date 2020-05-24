#include <bits/stdc++.h>

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

#define SZ  1010

int ping[SZ];
vector <int> ans;

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (cin >> s) {
        if (s == "0") break;

        mem(ping, 0);
        clr(ans);

        for (int i = 1; i < sz(s); i++) {
            if (s[i]-'0' == ping[i]) continue;

            ans.pb(i);
            for (int j = i; j < sz(s); j += i)
                ping[j] ^= 1;
        }

        for (int i = 0; i < sz(ans); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }


    return 0;
}


