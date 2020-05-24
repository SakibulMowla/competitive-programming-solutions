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
const ll mod = 1LL;

#define SZ  100010

bool f (int n) {
    int two = 0;
    while (n % 2 == 0) {
        n /= 2;
        two++;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    return (n == 1 && two);
}

ll a, b;

int bctk (ll n, bool s1, bool s2) {
    if (n > b) return 0LL;
    int ret = 0;
    if (n >= a) ret++;
    if (s2) ret += bctk(3LL * n, s1, 1);
    else ret += bctk(2LL * n, 1, s2) + bctk(3LL * n, s1, 1);
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
//
//    int n = 10000000;
//
//    vector <int> phi(n);
//
//    for (int i = 0; i < n; i++) {
//        phi[i] = i;
//    }
//
//    for (int i = 1; i < n; i++) {
//        for (int j = i + i; j < n; j += i) {
//            phi[j] -= phi[i];
//        }
//    }

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        cin >> a >> b;

        cout << bctk(2, 1, 0) + (int)(1 >= a && 1 <= b) << endl;
    }
//
//    int cnt = 0;
//    for (int i = 1; i < n; i++) {
//        if (i%phi[i] == 0) {
//            cout << ">>> i = " << i << endl;
//            cnt++;
//        }
//    }
//
//    cout << cnt << endl;

    return 0;
}




