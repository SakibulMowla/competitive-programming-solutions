#include <bits/stdc++.h>

using namespace  std;

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
const int inf = 1;
const ll mod = 1LL;

#define SZ  100010

int F (string &s) {
    int mx = 0, bal = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == '(') bal++;
        else bal--;
        if (bal > mx) mx = bal;
    }
    return mx;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> s;
        int n = F(s);
        for (int i = 0; i < n; i++) cout << '(';
        for (int i = 0; i < n; i++) cout << ')';
        cout << '\n';
    }

    return 0;
}




