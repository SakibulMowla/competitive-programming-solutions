#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;


#define SZ 100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    string s, t;
    string sprime, tprime;
    cin >> s >> t;
    sprime = s;
    tprime = t;

    vector <int> mp(200);
    for (int i = 'a'; i <= 'z'; i++) {
        mp[i] = (char)i;
    }

    for (int i = 0; i < sz(s); i++) {
        mp[s[i]] = t[i];
        mp[t[i]] = s[i];
    }

    for (int i = 0; i < sz(s); i++) {
        sprime[i] = mp[s[i]];
    }
    for (int i = 0; i < sz(t); i++) {
        tprime[i] = mp[t[i]];
    }

    if (sprime != t || tprime != s) {
        cout << -1 << endl;
    } else {
        set < pair <char, char> > ms;
        for (int i = 'a'; i <= 'z'; i++) {
            if (i != mp[i]) {
                ms.insert({min(i, mp[i]), max(i, mp[i])});
            }
        }
        cout << sz(ms) << endl;
        for (auto it: ms) {
            cout << it.X << ' ' << it.Y << endl;
        }
    }

    return 0;
}





