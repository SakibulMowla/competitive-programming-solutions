#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007;

#define SZ  100010


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    string beside[8];
    beside[0] = "LB";
    beside[1] = "MB";
    beside[2] = "UB";
    beside[3] = "LB";
    beside[4] = "MB";
    beside[5] = "UB";
    beside[6] = "SU";
    beside[7] = "SL";
    int add[8];
    add[0] = 3;
    add[1] = 3;
    add[2] = 3;
    add[3] = -3;
    add[4] = -3;
    add[5] = -3;
    add[6] = 1;
    add[7] = -1;

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        cout << n + add[(n - 1) % 8] << beside[(n - 1) % 8] << endl;
    }

    return 0;
}




