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

int minim[SZ][SZ];
int a[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    for (int cs = 0; cs < t; cs++) {
        int k;
        cin >> k;
        for (int i = 0; i < 15; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < 15; i++) {
            minim[i][i] = a[i];
            for (int j = i + 1; j < 15; j++) {
                minim[i][j] = min(minim[i][j-1], a[j]);
            }
        }

        int ans = 0;
        for (int i = 1; i <= 13; i++) {
            for (int j = i; j <= 13; j++) {
                if (minim[i][j] > max(a[i-1], a[j+1])) {
                    ans++;
                }
            }
        }

        cout << k << " " << ans << '\n';
    }

    return 0;
}




