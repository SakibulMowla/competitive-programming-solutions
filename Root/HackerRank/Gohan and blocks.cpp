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

map <string, int> mp;
string cmpr;
int cnt;

void bctk(int step, string &fnal, string &stk, string &gku) {
    if (!step) {
        if (fnal == cmpr) cnt++;
        mp[fnal] = 1;
    } else {
        if (sz(gku)) {
            stk.push_back(gku[0]);
            gku.erase(0, 1);
            bctk(step - 1, fnal, stk, gku);
            gku = stk[sz(stk)-1] + gku;
            stk.pop_back();
        }
        if (sz(stk)) {
            fnal.push_back(stk[sz(stk)-1]);
            stk.pop_back();
            bctk(step - 1, fnal, stk, gku);
            stk.push_back(fnal[sz(fnal)-1]);
            fnal.pop_back();
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("bubble.in", "r", stdin);
//        freopen("bubble.out", "w", stdout);
    #endif

    string s;
    cin >> s;
    cmpr = s;

    string fnal = "", stk = "";
    bctk(sz(s) * 2, fnal, stk, s);

    cout << cnt << ' ' << sz(mp) << endl;

    return 0;
}







