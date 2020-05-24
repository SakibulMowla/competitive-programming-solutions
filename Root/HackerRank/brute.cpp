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
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n;
    while (cin >> n) {

    vector <int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.pb(x);
    }

    bool flag = true;
    int ans = 0;

    while (flag) {
        flag = false;
        vector <int> v;
        for (int i = sz(a) - 1; i >= 1; i--) {
            if (a[i] > a[i-1]) {
                v.pb(i);
                if (!flag) {
                    flag = true;
                    ans++;
                }
            }
        }
        for (int i = 0; i < sz(v); i++) {
            a.erase(a.begin() + v[i]);
//            printf("v[i] = %d\n", v[i]);
        }
    }

    cout << ans << endl;
    }

    return 0;
}

/*
8
1 10
9 8
20 19
18 17
*/






