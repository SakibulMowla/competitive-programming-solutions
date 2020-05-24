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

bool possible (vector <ll>& v, int pos, ll r, ll c) {
    if (pos == 2) {
        if (r * c == v[2]) return true;
        return false;
    } else {
        bool ret = false;
        double dd = (double)v[pos] / (double)r;
        double dl = (ll)dd;
        if (dd - dl == 0 && dl >= 1 && dl <= c) {
            ret = possible(v, pos + 1, r, c - dl);
        }
        if (!ret) {
            double dd = v[pos] / c;
            double dl = (ll)dd;
            if (dd - dl == 0 && dl >= 1 && dl <= r) {
                ret = possible(v, pos + 1, r - dl, c);
            }
        }
        return ret;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        ll r, c, p, q, z;
        cin >> r >> c >> p >> q >> z;
        if (p + q + z == r * c) {
            vector <ll> v(3);
            v[0] = p;
            v[1] = q;
            v[2] = z;
            bool flag = false;
            sort(v.begin(), v.end());
            do {
                if (possible(v, 0, r, c)) {
                    flag = true;
                    break;
                }
            } while (next_permutation(v.begin(), v.end()));

            if (flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }


    return 0;
}





