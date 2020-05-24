#include <bits/stdc++.h>

using namespace  std;

typedef unsigned long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

typedef pair <int , int> pii;
typedef pair <ll , ll> pll;
const ll inf = 1;
const ll mod = 1LL;

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

ll brent_pollard_factor(ll n) {
    const ll m = 1000;
    ll a, x, y, ys, r, q, g;
    do
        a = rand() % n;
    while(a==0||a==n-2);
    y = rand() % n;
    r = 1;
    q = 1;

    do {
        x = y;
        for(ll i=0; i < r; i++) {
            // y = y² + a mod n
            y = mul(y, y, n);
            y += a;
            if(y < a)
                y += (ULLONG_MAX - n) + 1;
            y %= n;
        }

        ll k =0;
        do {
            for(ll i=0; i < m && i < r-k; i++) {
                ys = y;

                // y = y² + a mod n
                y = mul(y, y, n);
                y += a;
                if(y < a)
                    y += (ULLONG_MAX - n) + 1;
                y %= n;

                // q = q |x-y| mod n
                q = mul(q, (x>y)?x-y:y-x, n);
            }
            g = __gcd(q, n);
            k += m;
        } while(k < r && g == 1);

        r <<= 1;
    } while(g == 1);

    if(g == n) {
        do {
            // ys = ys² + a mod n
            ys = mul(ys, ys, n);
            ys += a;
            if(ys < a)
                ys += (ULLONG_MAX - n) + 1;
            ys %= n;

            g = __gcd((x>ys)?x-ys:ys-x, n);
        } while(g == 1);
    }

    return g;
}

#define SZ 1000010
#define MAXX 1E12

bool arr[SZ];
ll prime[SZ/10];
map <ll , int> mp;

void sieve () {
    int k = sqrt(SZ);
    for (ll i = 3; i < k; i += 2)
        if (!arr[i])
            for (ll j = i * i; j < SZ; j += i + i)
                arr[(int)j] = 1;
    int cnt = 0;
    prime[cnt++] = 2;
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime[cnt++] = i;
}

void factorize (ll n) {
    for (int i = 0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            int cnt = 0;
            while (n % prime[i] == 0) {
                n /= prime[i];
                cnt++;
            }
            mp[ prime[i] ] += cnt;
        }
    }
    if (n != 1) {
        mp[n]++;
    }
    return;
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

void solve (ll n) {
    if (n <= MAXX) {
        factorize(n);
        return;
    }

    if (isPrime(n)) {
        mp[n]++;
        return;
    }

    double d = sqrt((double)n);
    if((ll)d * (ll)d == n) {
        solve((ll)d);
        solve((ll)d);
        return;
    }

    ll p, q;

    for (int k = 0; k < 5; k++) {
        p = brent_pollard_factor(n);
        if (p!=n || p !=1) break;
    }
    if (p == 1 || p == n) {
        mp[n]++;
        return;
    }

    if (p <= MAXX) {
        factorize(p);
    } else {
        solve(p);
    }

    q = n / p;
    if (q <= MAXX) {
        factorize(q);
    } else {
        solve(q);
    }

    return;
}

void formatted_print (ll n) {
    bool mul = 0;
    printf("%llu =", n);
    for (map <ll , int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (mul) printf(" *");
        else mul = 1;
        printf(" %llu", it->X);
        if (it->Y > 1) printf("^%d", it->Y);
    }
    puts("");
}

int main() {
#if defined LOCAL
    freopen("1.txt", "r", stdin);
    freopen("2.txt", "w", stdout);
#endif

    sieve();

    int t;
    ll n;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        scanf("%llu", &n);

        clr(mp);
        if (n > 1) solve(n);
        else mp[1] = 1;

        formatted_print(n);
    }

    return 0;
}

