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

bool isPrime[SZ];

void sieve () {
    int lim = sqrt(SZ);
    isPrime[1] = 1;
    for (int i = 4; i < SZ; i += 2) {
        isPrime[i] = 1;
    }
    for (int i = 3; i <= lim; i++) {
        for (int j = i * i; j < SZ; j += i + i) {
            isPrime[j] = 1;
        }
    }
//    for (int i = 1; i < 100; i++) {
//        if (!isPrime[i]) {
//            cout << i << ' ';
//        }
//    }
//    cout << endl;
    return;
}

int DigitSquareSum (int n) {
    int ans = 0;
    while (n) {
        int digit = (n % 10);
        ans += digit * digit;
        n /= 10;
    }
    return ans;
}

bool isHappy (int n) {
    map <int, bool> mp;
    while (mp.find(n) == mp.end()) {
        mp[n] = true;
        if (n == 1) {
            return true;
        }
        n = DigitSquareSum(n);
    }
    return false;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);

    sieve();

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n, k;
        cin >> k >> n;
        cout << k << ' ' << n << ' ' << ((!isPrime[n] && isHappy(n))? "YES": "NO") << endl;
    }

    return 0;
}





