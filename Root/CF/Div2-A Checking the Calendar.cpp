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

    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    map <string, int> mp;

    mp["monday"] = 0;
    mp["tuesday"] = 1;
    mp["wednesday"] = 2;
    mp["thursday"] = 3;
    mp["friday"] = 4;
    mp["saturday"] = 5;
    mp["sunday"] = 6;

    string a, b;
    while (cin >> a >> b) {
        int x = mp[a];
        int y = mp[b];

        bool flag = false;
        for (int i = 0; i < 11; i++) {
            if ((x + days[i]) % 7 == y) {
                flag = true;
                break;
            }
        }

        cout << (flag? "YES": "NO") << endl;
    }


    return 0;
}





