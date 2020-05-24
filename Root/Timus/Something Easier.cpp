#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define clr(a) (a.clear())
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int, int>;
using pll = pair <ll, ll>;

const ll inf = 1;
const ll mod = 1E9;

#define SZ 100010

struct Solve {
    int n;

    Solve (int n): n(n) {
        if (isPrime(n)) {
            cout << n << endl;
        } else if (n % 2 == 0) {
            for (int i = 2; ; i++) {
                if (isPrime(i) && isPrime(n - i)) {
                    cout << i << ' ' << n - i << endl;
                    break;
                }
            }
        } else {
            if (isPrime(n - 2)) {
                cout << 2 << ' ' << n - 2 << endl;
            } else {
                for (int i = n; ; i -= 2) {
                    if (isPrime(i)) {
                        for (int j = 2; ; j++) {
                            if (isPrime(j) && isPrime(n - i - j)) {
                                cout << j << ' ' << n - i - j << ' ' << i << endl;
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

    bool isPrime (int k) {
        if (k == 1) return false;
        for (int i = 2; (ll)i * (ll)i <= (ll)k; i++) {
            if (k % i == 0)
                return false;
        }
        return true;
    }
};

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;
        Solve Task(n);
    }

    return 0;
}


