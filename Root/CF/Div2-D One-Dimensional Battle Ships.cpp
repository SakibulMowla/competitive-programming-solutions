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

#define SZ 200010

int calc (int l, int r, int a) {
    int n = r - l - 1;
    if (n >= a) return 1 + (n - a) / (a + 1);
    return 0;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);

    int n, k, a;
    cin >> n >> k >> a;

    int x;
    cin >> x;
    vector <int> v(x);

    for (int i = 0; i < x; i++) {
        cin >> v[i];
    }

    int ans = calc(0, n + 1, a);
    int indx = -1;

    map <pii, int> mp;
    set <int> ms;

    mp[{0, n + 1}] = ans;
    ms.insert(0);
    ms.insert(n + 1);

    for (int i = 0; i < x; i++) {
        auto it = ms.upper_bound(v[i]);
        int l = *prev(it), r = *it;
        ans = ans - mp[{l, r}] + (mp[{l, v[i]}] = calc(l, v[i], a)) + (mp[{v[i], r}] = calc(v[i], r, a));
        if (ans < k) {
            indx = i + 1;
            break;
        }
        ms.insert(v[i]);
    }

    cout << indx << endl;


    return 0;
}







