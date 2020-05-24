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

struct data {
    string name;
    int id;
    vector <string> availability;
    data () {
        availability = vector <string> (24, "");
    }
};

map <string, int> mp;

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector <data> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i].name;
        int x;
        cin >> x;
        cities[i].id = 0;
        mp[cities[i].name] = i;
        for (int j = 0; j < x; j++) {
            string a, b;
            cin >> a >> b;
            for (int k = 0; k < 24; k++) {
                if (a[k] == '.') {
                    cities[i].availability[k] = b;
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        bool flag = false;
        int x;
        cin >> x;
        vector <string> dists(x), ans(x);
        for (auto &p: dists) cin >> p;
        for (int i = 0; i < 24; i++) {
            bool tflag = true;
            for (int j = 0; j < x; j++) {
                if (cities[mp[dists[j]]].availability[i] == "") {
                    tflag = false;
                    break;
                }
                ans[j] = cities[mp[dists[j]]].availability[i];
            }
            if (tflag == true) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "Yes";
            for (auto p: ans) cout << ' ' << p;
            cout << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}





