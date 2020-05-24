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

#define SZ  100010

ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;}

bool arr[SZ];
vector <int> prime;

void sieve () {
    int k = sqrt(SZ);
    for (int i = 3; i < k; i += 2)
        if (!arr[i])
            for (int j = i * i; j < SZ; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for (int i = 3; i < SZ; i += 2)
        if (!arr[i])
            prime.pb(i);
}

ll totient (ll n) {
    ll ans = n;
    for (int i = 0; prime[i] * prime[i] <= n; i++) {
        if (n % prime[i] == 0) {
            while (n % prime[i] == 0) n /= prime[i];
            ans *= ((ll)prime[i] - 1LL);
            ans /= (ll)prime[i];
        }
    }
    if (n != 1) {
        ans *= (n-1LL);
        ans /= n;
    }
    return ans;
}

ll mod(ll a, ll b) {
  return ((a%b)+b)%b;
}

ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  ll xx = y = 0;
  ll yy = x = 1;
  while (b) {
    ll q = a/b;
    ll t = b; b = a%b; a = t;
    t = xx; xx = x-q*xx; x = t;
    t = yy; yy = y-q*yy; y = t;
  }
  return a;
}

ll mod_inverse(ll a, ll n) {
  ll x, y;
  ll d = extended_euclid(a, n, x, y);
  if (d > 1) return -1;
  return mod(x,n);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    ll N, E, C;
    while (cin >> N >> E >> C) {
        cout << BigMod(C, mod_inverse(E, totient(N)), N) << '\n';
    }

    return 0;
}






