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

ll f[20];

struct Solve {
    string s;
    map <char, int> mp;
    ll k;

    Solve (string s, ll k): s(s), k(k) {
        for (auto ch: s) {
            mp[ch]++;
        }
        bctk(k);
        cout << endl;
    }

    void bctk(ll lft) {
        int tot = 0;
        vector <int> v;

        for (auto it = mp.begin(); it != mp.end(); it++) if (it->second) {
            tot += it->second;
            v.pb(it->second);
        }

        for (auto it = mp.begin(); it != mp.end(); it++) if (it->second) {
            ll tmp = f[tot - 1];
            bool flag = false;
            for (auto i: v) {
                if (i == it->second && !flag) {
                    flag = true;
                    tmp /= f[it->second-1];
                } else {
                    tmp /= f[i];
                }
            }
            if (lft - tmp > 0) {
                lft -= tmp;
            } else {
                cout << it->first;
                it->second--;
                return bctk(lft);
            }
        }
    }
};

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif


    ios::sync_with_stdio(false);

    f[0] = 1;
    for (int i = 1; i <= 16; i++) {
        f[i] = (ll)i * f[i-1];
    }

    string s;
    ll k;
    while (cin >> s >> k) {
        if (s == "#" && k == 0) break;
        Solve Task(s, k);
    }


    return 0;
}




