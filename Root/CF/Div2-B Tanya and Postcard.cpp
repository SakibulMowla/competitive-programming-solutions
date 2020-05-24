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

int cnt[400];
int f[2*SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    string s, t;
    while (cin >> s >> t) {
        mem(f, 0);
        for (int i = 0; i < sz(t); i++) {
            cnt[t[i]]++;
        }
        int a = 0, b = 0;
        for (int i = 0; i < sz(s); i++) {
            if (cnt[s[i]]) {
                cnt[s[i]]--;
                a++;
                f[i] = 1;
            }
        }
        for (int i = 0; i < sz(s); i++) {
            if (!f[i]) {
                char ch = (s[i] == toupper(s[i])) ? tolower(s[i]) : toupper(s[i]);
                if (cnt[ch]) {
                    cnt[ch]--;
                    b++;
                }
            }
        }
        cout << a << ' ' << b << '\n';
    }


    return 0;
}







