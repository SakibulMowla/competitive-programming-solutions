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

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110


int main() {
//    #if defined JESI
//        freopen("1.txt", "r", stdin);
        freopen("1.txt", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int t = 10;
    cout << t << endl;

    for (int i = 0; i < t; i++) {
        int a = rand() % 100000;
        int b = rand() % 100000;
        int n = rand() % 1000 + 1;
        int k = rand() % 1000 + 1;
        cout << a << ' ' << b << ' ' << n << ' ' << k << endl;
    }


    return 0;
}



