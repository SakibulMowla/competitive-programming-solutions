#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  110

pii Min (pii p, pii q) {
    if (p.X*q.Y < p.Y*q.X) return p;
    return q;
}

int gcd (int p, int q) {
    if (q == 0) return p;
    return gcd(q, p%q);
}

int a[SZ], b[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    pii ans = {1, 0};

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        int g = gcd(a[i], b[i]);
        a[i] /= g;
        b[i] /= g;
        swap(a[i], b[i]);
        ans = Min({a[i], b[i]}, ans);
    }

//    cout << ans.X << ' ' << ans.Y << endl;

    for (int i = 0; i < n; i++) {
        if (make_pair(a[i], b[i]) == ans) {
            cout << i + 1 << endl;
        }
    }


    return 0;
}







