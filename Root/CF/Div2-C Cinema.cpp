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

    map <int, int> mp;

    vector <int> a(n);
    for (auto &x: a) {
        cin >> x;
        if (mp.find(x) == mp.end()) mp[x] = 1;
        else mp[x]++;
    }

    int m;
    cin >> m;

    vector <int> b(m), c(m);
    for (auto &x: b) {
        cin >> x;
    }
    for (auto &x: c) {
        cin >> x;
    }

    int indx = 1;
    pii best = {0, 0};

    for (int i = 0; i < m; i++) {
        int x = (mp.find(b[i]) == mp.end())? 0: mp[b[i]];
        int y = (mp.find(c[i]) == mp.end())? 0: mp[c[i]];

        if (x > best.X || (x == best.X && y > best.Y)) {
            indx = i + 1;
            best = {x, y};
        }
    }

    cout << indx << endl;

    return 0;
}





