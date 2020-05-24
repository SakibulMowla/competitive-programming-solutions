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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        string s, t;
        cin >> s >> t;

        int szero = 0, sone = 0, tzero = 0, tone = 0;
        for (int i = 0; i < sz(s); i++) {
            if (s[i] == '0') {
                szero++;
            } else if (s[i] == '1') {
                sone++;
            }
            if (t[i] == '0') {
                tzero++;
            } else if (t[i] == '1') {
                tone++;
            }
        }

        if (sone > tone) {
            cout << "Case " << cs + 1 << ": -1" << '\n';
        } else{
            int moves = 0, swaps = 0;
            for (int i = 0; i < sz(s); i++) {
                if (s[i] == t[i]) {
                    continue;
                }
                if (s[i] == '0') {
                    if (t[i] == '1') {
                        if (sone + 1 <= tone) {
                            sone++;
                            szero--;
                            moves++;
                        } else {
                            swaps++;
                        }
                    }
                }
                if (s[i] == '1') {
                    if (t[i] == '0') {
                        swaps++;
                    }
                }
                if (s[i] == '?') {
                    if (t[i] == '0') {
                        if (szero + 1 <= tzero) {
                            szero++;
                            moves++;
                        } else {
                            sone++;
                            moves++;
                            swaps++;
                        }
                    } else if (t[i] == '1') {
                        if (sone + 1 <= tone) {
                            sone++;
                            moves++;
                        } else {
                            szero++;
                            moves++;
                            swaps++;
                        }
                    }
                }
            }
            assert(swaps%2 == 0);
            cout << "Case " << cs + 1 << ": " << moves + swaps/2 << '\n';
        }
    }

    return 0;
}




