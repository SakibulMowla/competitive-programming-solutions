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

    int fours = n, twos = 2 * n;

    vector <int> a(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        while (a[i] >= 3 && fours) {
            fours--;
            a[i] -= 4;
        }
    }


    for (int i = 0; i < k; i++) {
        while (a[i] >= 2 && twos) {
            twos--;
            a[i] -= 2;
        }
    }

    int ONES = 0, TWOS = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == 1) ONES++;
        else if (a[i] == 2) TWOS++;
        else if (a[i] > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }

    while (fours) {
        if (ONES <= 0) {
            TWOS--;
            if (TWOS > 0) {
                TWOS--;
                ONES = 1;
            }
        } else if (TWOS <= 0) {
            ONES -= 2;
        } else {
            ONES--;
            TWOS--;
        }
        fours--;
    }

    while(twos--) {
        if (ONES > 0) ONES--;
        else if (TWOS > 0) TWOS--;
    }

    bool flag = (ONES <= 0 && TWOS <= 0);

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}


