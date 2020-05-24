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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    bool flag = true;
    int pre = -1;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        val = (i - val + n) % n;
        if (i & 1) val = n - val;
        val %= n;
        if (pre != -1 && val != pre) flag = false;
        pre = val;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}







