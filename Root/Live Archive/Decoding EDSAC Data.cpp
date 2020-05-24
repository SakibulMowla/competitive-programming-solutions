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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

map <char , int> mp;
double two[40];

int flip (int n) {
    int m = 0;
    for (int i = 0; i <= 16; i++) {
        if (n & (1<<i)) continue;
        m |= 1 << i;
    }
    return m;
}

void solve (int number, int sain) {
    double ans = 0;
    for(int i = 0; i < 17; i++) {
        if (number & (1<<i)) {
            ans = ans + two[i];
        }
    }
    if (sain) {
        ans = -ans;
    }

    if (ans == -1.0) {
        cout << "-1.0\n";
        return;
    } else if (ans == 0.0) {
        cout << "0.0\n";
        return;
    }

    stringstream ss;
    ss << fixed << setprecision(20) << ans;
    string s;
    ss >> s;
    while (1) {
        if (s[ sz(s)-1 ] == '0') {
            s.erase(sz(s)-1);
        } else {
            break;
        }
    }
    cout << s << '\n';
}

int addone (int n) {
    for (int i = 16; i >= 0; i--) {
        if (n & (1<<i)) {
            n = n & ~(1<<i);
        } else {
            n |= (1<<i);
            break;
        }
    }
    return n;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    string s = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";

    for (int i = 0; i < sz(s); i++) {
        mp[ s[i] ] = i;
    }
    two[0] = 1.0;
    for (int i = 1; i < 20; i++) {
        two[i] = two[i-1] / 2.0;
    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int test, n;
        char a, pf;
        cin >> test >> a >> n >> pf;

        cout << test << ' ';

        int now = 1;
        int number = 0;

        if (mp[a] & (1<<4)) {
            number = 1 << 0;
        }
        for (int i = 3; i >= 0; i--) {
            if (mp[a] & (1<<i)) {
                number |= 1 << now;
            }
            now++;
        }
        for (int i = 10; i >= 0; i--) {
            if (n & (1<<i)) {
                number |= 1 << now;
            }
            now++;
        }
        if (pf == 'D') {
            number |= 1 << now;
        }
        if (mp[a] & (1<<4)) {
            number = flip(number);
            number = addone(number);
        }

        solve(number, mp[a] & (1<<4));
    }



    return 0;
}



