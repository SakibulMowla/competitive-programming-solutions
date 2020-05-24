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
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) cin >> x;

    vector<int> b(a);

    sort(b.begin(), b.end());
    map<int, int> mp;

    int sz = 0;
    for (auto x: b) mp[x] = sz++;

    for (auto &x: a) x = mp[x];

    vector<bool> flag(n, false);

    vector<vector<int>> ans;
    sz = 0;

    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            int j = i;
            ans.pb(vector<int>());
            while (flag[j] == false) {
                flag[j] = true;
                ans[sz].pb(j);
                if (j != a[j]) j = a[j];
            }
            sz++;
        }
    }

    cout << sz << endl;
    for (auto &x: ans) {
        cout << sz(x);
        for (auto y: x) cout << ' ' << y + 1;
        cout << endl;
    }

    return 0;
}




