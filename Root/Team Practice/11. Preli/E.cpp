#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  100010

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool valid (int d, int m) {
    if(d > 12 && m > 12) return false;
    if(d <= 12) if(month[d] < m) return false;
    if(m <= 12) if(month[m] < d) return false;
    return true;
}

bool after(int d1, int m1, int d2, int m2) {
    if(m1 > 12 || m2 > 12) return 0;
    return ((m1 < m2) || (m1 == m2 && d1 < d2));
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int d1, m1, d2, m2;
        cin >> d1 >> m1 >> d2 >> m2;

        cout << "Case " << cs+1 << ": ";

        if(!valid(d1, m1) || !valid(d2, m2)) cout << "I am sure there is some kinda mistake!\n";
        else {
            bool f1 = after(d1, m1, d2, m2);
            bool f2 = after(m1, d1, m2, d2);
            if(f1 == 1 && f2 == 1) cout << "Oh no it is ambiguous!\n";
            else if(f1 || f2) cout << "Okay got it!\n";
            else cout << "I am sure there is some kinda mistake!\n";
        }
    }


    return 0;
}




