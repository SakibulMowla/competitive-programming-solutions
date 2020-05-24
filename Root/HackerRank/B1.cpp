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

#define SZ  5010

int a[SZ];
ll c[SZ][SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[i]) {
                c[i][k] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = n - 1; k >= 0; k--) {
            c[i][k] += c[i][k+1];
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                if (j + 1 < n) {
                    ans += c[i][j+1];
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}







