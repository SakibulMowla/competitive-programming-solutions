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

ll mul(ll a,ll b,ll mod) {
    ll ret = 0;
    while (b) {
        if(b & 1) {
            ret += a;
            if(ret >= mod) ret -= mod;
        }
        a = a<<1;
        if(a >= mod) a -= mod;
        b = b>>1;
    }
    return ret;
}

bool isPrime(ll a, ll n) {
    ll x = 1, step = 1LL << 60, rx;
    while (step > n-1) step >>= 1;
    while (step > 0) {
        rx = mul(x,x,n);
        if (rx == 1 && x != 1 && x != n-1) return 0;
        x = rx;
        if (step & (n-1)) x = mul(x,a,n);
        step >>= 1;
    }
    return x == 1;
}

bool isPrime(ll n) {
    if (n < 100) {
        for (int i=2; i<n; i++)
            if (n % i == 0) return false;
        return true;
    }
    return isPrime(2,n) && isPrime(7,n) && isPrime(61,n) && isPrime(13,n);
}

void solve (int n) {
    if (isPrime(n - 2)) {
        cout << 2 << ' ' << n - 2 << endl;
    } else {
        for (int i = 3; ; i+=2) {
            if (isPrime(i) && isPrime(n - i)) {
                cout << i << ' ' << n - i << endl;
                break;
            }
        }
    }
    return;
}

int main() {
#if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
#endif

    ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    if (isPrime(n)) {
        cout << 1 << endl << n << endl;
    } else if (isPrime(n - 2)) {
        cout << 2 << endl << 2 << ' ' << n - 2 << endl;
    } else {
        for (int i = n; ; i -= 2) {
            if (n - i >= 4 && isPrime(i)) {
                cout << 3 << ' ' << i << ' ';
                solve(n - i);
                break;
            }
        }
    }

    return 0;
}


