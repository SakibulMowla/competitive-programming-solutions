#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    string a, b;
    cin >> a >> b;

    string c = a;
    string d = b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a != b) {
        cout << -1 << endl;
    } else {
        int cnt = 0;
        for (int i = 0; i < sz(a); i++) {
            if (c[i] != d[i]) {
                cnt++;
            }
        }
        cout << cnt/2 << endl;
    }

    return 0;
}



