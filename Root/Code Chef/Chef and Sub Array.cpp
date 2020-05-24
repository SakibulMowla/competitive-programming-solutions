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

    int n, k, p;
    cin >> n >> k >> p;

    vector <int> a(n + p);

    for (int i = 0; i < n; i++) cin >> a[p + i];
    for (int i = p - 1; i >= 0; i--) a[i] = a[i + n];

    k = min(k, n);

    vector <int> window(n + p);

    for (int i = n + p - 1, cnt = 0; i >= 0; i--) {
        cnt += a[i];
        if (i + k < n + p) cnt -= a[i + k];
        window[i] = cnt;
    }

    multiset <int> ms;
    for (int i = p; i <= n + p - k; i++) {
        ms.insert(window[i]);
    }

    string s;
    cin >> s;

    for (auto x: s) {
        if (x == '!') {
            ms.erase(ms.find(window[n + p - k]));
            ms.insert(window[--p]);
        } else {
            cout << *(prev(ms.end())) << endl;
        }
    }

    return 0;
}



