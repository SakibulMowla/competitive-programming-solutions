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

vector <string> v[4];

int syllable (string s) {
    assert(sz(s));
    if (sz(s) == 6) {
        for (int i = 0; i < 5; i++) {
            if (tolower(s[i]) == 'n' && (s[i+1] == 'g' || s[i+1] == 'y')) {
                return 2;
            }
        }
        return 3;
    } else if (sz(s) == 3) {
        if (tolower(s[0]) == 'a' || tolower(s[0]) == 'e' || tolower(s[0]) == 'i' || tolower(s[0]) == 'o' || tolower(s[0]) == 'u') {
            return 2;
        }
        return 1;
    } else if (sz(s) >= 6) {
        return 3;
    } else if (sz(s) == 4 || sz(s) == 5) {
        return 2;
    } else {
        return 1;
    }
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

//    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s;
        int n = 0;

        for (int i = 0; i < 4; i++) {
            clr(v[i]);
        }

        while (true) {
            char c = getchar();
            if (c == ' ' || c == '\n') {
                if (sz(s)) {
                    if (n < 4) v[n].pb(s);
                }
                s.clear();
                continue;
            }
            if (c == ',' || c == '.') {
                if (n < 4) {
                    if (sz(s)) v[n].pb(s);
                }
                s.clear();
                n++;
                if (c == '.') {
                    break;
                }
                continue;
            }
            if (n < 4) {
                s.pb(c);
            }
        }

        int a = 0, b = 0, c = 0, d = max(0, (n - 4) * 10);

        int cnt[6];

        for (int i = 0; i < min(4, n); i++) {
            int tmp = 0;
            for (int j = 0; j < sz(v[i]); j++) {
                tmp += syllable(v[i][j]);
            }
            if (tmp >= 8 && tmp <= 12) {
                a += 10;
            }
            cnt[i] = tmp;
        }

        if (n >= 3) {
            string s1 = v[0][sz(v[0])-1];
            string s2 = v[2][sz(v[2])-1];
            s1 = s1.substr(sz(s1) - 2);
            s2 = s2.substr(sz(s2) - 2);
            if (s1 == s2)
                b += 20;
            if (cnt[0] == cnt[2]) {
                c += 10;
            }
        }

        if (n >= 4) {
            string s1 = v[1][sz(v[1])-1];
            string s2 = v[3][sz(v[3])-1];
            s1 = s1.substr(sz(s1) - 2);
            s2 = s2.substr(sz(s2) - 2);
            if (s1 == s2)
                b += 20;
            if (cnt[1] == cnt[3]) {
                c += 10;
            }
        }

        int e = a + b + c - d;

        cout << "Case #" << cs + 1 << ": " << a << " " << b << " " << c << " " << d << " " << e << endl;
    }


    return 0;
}







