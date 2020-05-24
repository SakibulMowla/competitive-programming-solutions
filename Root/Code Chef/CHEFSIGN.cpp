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

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s = ".", a;
        cin >> a;
        for (auto ch: a) if (ch != '=') s.push_back(ch);
        int n = s.size();
        int ans = 1, streak = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) streak = 1;
            else streak++;
            ans = max(ans, streak + 1);
        }
        cout << ans << endl;
    }

    return 0;
}




