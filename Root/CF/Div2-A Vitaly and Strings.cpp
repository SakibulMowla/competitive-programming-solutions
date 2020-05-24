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

#define SZ 110

int dp[SZ][2][2];

string s, t;
int n;

int solve (int pos, int f1, int f2) {
    if (pos == n) return (f1==0 && f2==0);
    int &ret = dp[pos][f1][f2];
    if (ret != -1) return ret;
    ret = 0;
    char strt = f1 ? s[pos] : 'a';
    char endd = f2 ? t[pos] : 'z';
    for (char i = strt; i <= endd; i++) {
        int nf1 = (f1 && i==strt);
        int nf2 = (f2 && i==endd);
        ret |= solve(pos+1, nf1, nf2);
    }
    return ret;
}

void path (int pos, int f1, int f2) {
    if (pos == n) return;
    char strt = f1 ? s[pos] : 'a';
    char endd = f2 ? t[pos] : 'z';
    for (char i = strt; i <= endd; i++) {
        int nf1 = (f1 && i==strt);
        int nf2 = (f2 && i==endd);
        if (solve(pos+1, nf1, nf2)) {
            cout << i;
            return path(pos+1, nf1, nf2);
        }
    }
    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif
    FAST
    while (cin >> s >> t) {
        n = sz(s);
        mem(dp, -1);
        if (!solve(0, 1, 1)) cout << "No such string";
        else path(0, 1, 1);
        cout << endl;
    }


    return 0;
}







