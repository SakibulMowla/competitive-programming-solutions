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

    int a, b, c;
    cin >> a >> b >> c;

    int ans = 0;
    for (int i = 1; i <= 1000; i++) {
        if (i <= a && 2 * i <= b && 4 * i <= c) {
            ans = 7 * i;
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}





