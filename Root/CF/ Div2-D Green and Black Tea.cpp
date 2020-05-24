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
    ios::sync_with_stdio(false);

    string s = "GB";

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    if (a == 0) {
        if (b <= k) {
            cout << string(b, 'B') << endl;
        } else {
            cout << "NO" << endl;
        }
    } else if (b == 0) {
        if (a <= k) {
            cout << string(a, 'G') << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (b > a) {
            swap(a, b);
            swap(s[0], s[1]);
        }

        string ans = "";
        while (b--) {
            ans += string((a - k) >= b? k: a - b, s[0]) + s[1];
            a -= (a - k) >= b? k: a - b;
        }

        if (a <= k) {
            if (a) cout << ans <<  string(a, s[0]) << endl;
            else cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}




