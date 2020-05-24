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

    int n;
    while (cin >> n) {
        string s;
        cin >> s;

        int ans = 0;
        for (int i = 0; i < sz(s); i++) {
            int x = 0, y = 0;
            for (int j = i; j < sz(s); j++) {
                if (s[j] == 'U') y++;
                else if (s[j] == 'D') y--;
                else if (s[j] == 'L') x--;
                else x++;
                if (x == 0 && y == 0) ans++;
            }
        }

        cout << ans << endl;
    }


    return 0;
}





