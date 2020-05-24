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

    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector <ll> c(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (i != k) sum += x;
    }
    ll b;
    cin >> b;
    sum /= 2;

    if (b == sum) cout << "Bon Appetit" << endl;
    else cout << abs(b - sum) << endl;

    return 0;
}



