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

#define SZ  1010

vector <int> votes[SZ];
string s[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int n, k;

    while (cin >> k >> n && (k + n)) {
        for (int i = 1; i <= n; i++) {
            clr(votes[i]);
        }

        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            for (int j = 0; j < k; j++) {
                int v;
                cin >> v;
                votes[v].pb(i);
            }
        }

        int bad = 0;

        for (int i = 1; i <= n; i++) {
            bool f = 0;
            sort(votes[i].begin(), votes[i].end());

            if (sz(votes[i]) != k)
                f = 1;
            else {
                for (int j = 0; j < sz(votes[i]); j++) {
                    if (s[i] == s[ votes[i][j] ]) {
                        f = 1;
                        break;
                    }
                    if (j && votes[i][j] == votes[i][j-1]) {
                        f = 1;
                        break;
                    }
                }
            }

            bad += f;
        }

        if (bad == 0) cout << "NO PROBLEMS FOUND\n";
        else if (bad == 1) cout << "1 PROBLEM FOUND\n";
        else cout << bad << " PROBLEMS FOUND\n";
    }


    return 0;
}







