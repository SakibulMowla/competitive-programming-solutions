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

    int n, k;
    cin >> n >> k;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ans += (x + k - 1) / k;
    }

    cout << (ans + 1) / 2 << endl;

    return 0;
}




