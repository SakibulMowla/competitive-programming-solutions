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

    int n;
    string s, ans;
    cin >> n >> s;
    ans = s;

    int lft, rht, idx = 0;
    if (n & 1) {
//        cout << s[n/2];
        ans[n/2] = s[idx++];
        lft = n/2 - 1;
        rht = n/2 + 1;
    } else {
        lft = n/2 - 1;
        rht = n /2;
    }

    while (lft >= 0 && rht < n) {
//        cout << s[lft] << s[rht];
        ans[lft] = s[idx++];
        ans[rht] = s[idx++];
        lft--;
        rht++;
    }
    cout << ans << endl;

    return 0;
}





