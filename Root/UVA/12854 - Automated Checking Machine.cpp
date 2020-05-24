#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

#define SZ 100010


int main() {
    #if defined LOCAL
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int a[5], b[5];

    while (cin >> a[0]) {
        for (int i = 1; i < 5; i++)
            cin >> a[i];
        for (int i = 0; i < 5; i++)
            cin >> b[i];
        int i;
        for (i = 0; i < 5; i++)
            if (a[i] == b[i])
                break;
        cout << (i == 5 ? "Y\n" : "N\n");
    }

    return 0;
}







