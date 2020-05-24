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

    vector <int> price(n);
    for (auto &x: price) {
        cin >> x;
    }
    sort(price.begin(), price.end());

    int q;
    cin >> q;

    vector <pii> balance(q);
    for (int i = 0; i < q; i++) {
        cin >> balance[i].X;
        balance[i].Y = i;
    }
    sort(balance.begin(), balance.end());

    vector <int> ans(q);
    for (int i = 0, j = 0; i < q; i++) {
        for (; j < n && balance[i].X >= price[j]; j++) {
            ;
        }
        ans[balance[i].Y] = j;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }


    return 0;
}





