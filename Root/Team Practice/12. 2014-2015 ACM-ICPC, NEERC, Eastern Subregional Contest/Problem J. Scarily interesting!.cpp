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

#define SZ  110

int diff = 0;

bool comp(int a, int b) {
    return abs(diff+a) < abs(diff+b);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    while(cin >> n) {
        vector <pii> a(n), b(n);
        int st1, st2;
        st1 = st2 = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i].X;
            st1 += a[i].X;
            a[i].Y = i + 1;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].X;
            st2 += b[i].X;
            b[i].Y = i + 1;
        }
        if(st1 < st2)  {
            sort(a.begin(), a.end(), greater <pii> ());
            sort(b.begin(), b.end());
        } else {
            sort(b.begin(), b.end(), greater <pii> ());
            sort(a.begin(), a.end());
        }
        for (int i = 0; i < n; i++) {
            printf("%d %d\n", a[i].Y, b[i].Y);
        }
    }

    return 0;
}






