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
//const ll mod = 1LL;

#define SZ  110

ll s;
map <pii, bool> mp;
bool found;

bool possible (ll a, ll b) {
    if (a == s || b == s) {
        return found = 1;
    }
    if (found) {
        return found;
    }
    if (mp.find(MP(a, b)) != mp.end()) {
        return found;
    } else {
        mp[ MP(a, b) ] = 1;
        if (a + b <= s) found |= possible(a + b, b) | possible(a, a + b);
        return found;
    }
}

// return a % b (positive value)
ll mod(ll a, ll b) {
  return ((a%b)+b)%b;
}

// computes gcd(a,b)
ll gcd(ll a, ll b) {
  ll tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}

// computes lcm(a,b)
ll lcm(ll a, ll b) {
  return a/gcd(a,b)*b;
}

// returns d = gcd(a,b); finds x,y such that d = ax + by
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

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);

    ll a, b, c;
    while (cin >> a >> b >> c) {
        if (c == 0) {
            if (a == 0 || b == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (a == 0 && b == 0) {
            if (c == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (a == 0 || b == 0) {
            if (c % (a+b) == 0 ) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            ll x, y;
            ll g = extended_euclid(a, b, x, y);
            if (c % g != 0) {
                cout << "NO\n";
                continue;
            }
            x = x * c / g;
            y = y * c / g;

            ll lo = (ll)( (double)(-x) * (double)g / (double)b );
            ll hi = (ll)( (double)(y) * (double)g / (double)a );

            lo++;
            hi--;

            if (lo <= hi) cout << "YES\n";
            else cout << "NO\n";
         }
    }

    return 0;
}






