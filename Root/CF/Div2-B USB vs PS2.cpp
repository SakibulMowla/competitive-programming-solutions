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

    int a, b, c;
    cin >> a >> b >> c;

    vector <ll> u, p;

    int m;
    cin >> m;


    for (int i = 0; i < m; i++) {
        ll x;
        string s;
        cin >> x >> s;
        if (s[0] == 'U') u.pb(x);
        else p.pb(x);
    }

    int n1 = u.size(), n2 = p.size();
    sort(u.begin(), u.end());
    sort(p.begin(), p.end());

    int cnt = 0;
    ll cost = 0;

    for (int i = 0; i < min(n1, a); i++) {
        cnt++;
        cost += u[i];
    }

    for (int i = 0; i < min(n2, b); i++) {
        cnt++;
        cost += p[i];
    }

    int indx1 = min(n1, a), indx2 = min(n2, b);
    for (int i = 0; i < c; i++) {
        if (indx1 == n1) {
            if (indx2 < n2) {
                cnt++;
                cost += p[indx2++];
            }
        } else if (indx2 == n2) {
            if (indx1 < n1) {
                cnt++;
                cost += u[indx1++];
            }
        } else {
            cnt++;
            cost += min(u[indx1], p[indx2]);
            if (u[indx1] == min(u[indx1], p[indx2])) indx1++;
            else indx2++;
        }
    }

    cout << cnt << ' ' << cost << endl;

    return 0;
}





