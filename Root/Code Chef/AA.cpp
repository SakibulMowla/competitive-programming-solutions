#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, m;
        cin >> n >> m;
        swap(n, m);

        string s;
        cin >> s;

        bool flag = false;
        for (int i = 1; i <= n && !flag; i++) {
            for (int j = 1; j <= m; j++) {
                int x = i, y = j;
                bool tmp = true;
                for (int k = 0; k < sz(s); k++) {
                    if (s[k] == 'U') y++;
                    else if (s[k] == 'D') y--;
                    else if (s[k] == 'L') x--;
                    else if (s[k] == 'R') x++;
                    if (x > n || x < 1 || y > m || y < 1) {
                        tmp = false;
//                        cout << ">> " << i << ' ' << j << " " << x << " " << y << endl;
                        break;
                    }
                }
                if (tmp == true) {
                    flag = true;
                    break;
                }
            }
        }

        cout << (flag? "safe": "unsafe") << endl;
    }

    return 0;
}




