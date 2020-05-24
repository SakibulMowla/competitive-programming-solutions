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

ll pwr[12][12];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    for (int i = 1; i <= 9; i++) {
        pwr[i][0] = 1LL;
        for (int j = 1; j <= 10; j++) {
            pwr[i][j] = pwr[i][j-1] * (ll)i;
        }
    }

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        ll n;
        cin >> n;

        ll tmp = n, len = 0;
        while(tmp) {
            len++;
            tmp /= 10;
        }

        ll sum = 0LL;
        tmp = n;
        while (tmp) {
            sum += pwr[ tmp%10 ][len];
            tmp /= 10;
        }

        if (n == sum) cout << "Armstrong\n";
        else cout << "Not Armstrong\n";
    }

    return 0;
}






