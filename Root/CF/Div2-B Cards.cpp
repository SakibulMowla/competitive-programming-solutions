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

bool rf, bf, gf;
bool dp[210][210][210];

void bctk (int r, int g, int b) {
    if (r + g + b == 1) {
        if (r == 1) rf = true;
        if (g == 1) gf = true;
        if (b == 1) bf = true;
    } else {
        if (dp[r][g][b]) return;
        dp[r][g][b] = true;

        if (r && g) bctk(r - 1, g - 1, b + 1);
        if (r && b) bctk(r - 1, g + 1, b - 1);
        if (g && b) bctk(r + 1, g - 1, b - 1);
        if (r >= 2) bctk(r - 1, g, b);
        if (g >= 2) bctk(r, g - 1, b);
        if (b >= 2) bctk(r, g, b - 1);
    }
    return;
}

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

        int r = 0, g = 0, b = 0;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == 'R') r++;
            else if (s[i] == 'G') g++;
            else b++;
        }

        rf = false, bf = false, gf = false;
        mem(dp, false);

        bctk(r, g, b);

        if (bf) cout << 'B';
        if (gf) cout << 'G';
        if (rf) cout << 'R';
        cout << endl;
    }

    return 0;
}





