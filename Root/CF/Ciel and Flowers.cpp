#include "stdio.h"
#include "string.h"
#include "string"
#include "stdlib.h"
#include "math.h"
#include "map"
#include "vector"
#include "queue"
#include "stack"
#include "set"
#include "iostream"
#include "algorithm"

using namespace  std;

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

//%I64d
int main()
{
    ll n,r,g,b,r1,g1,b1,tot,one,two;

    while(cin >> r >> g >> b)
    {
        tot = one = two = 0;
        tot += (r/3);
        r1 = r % 3;

        tot += (g/3);
        g1 = g % 3;

        tot += (b/3);
        b1 = b % 3;

        if(b1 == 1) one++;
        if(r1 == 1) one++;
        if(g1 == 1) one++;

        if(b1 == 2) two++;
        if(g1 == 2) two++;
        if(r1 == 2) two++;

        if(one == 3) tot++;
        else if(two == 3) tot+=2;
        else if(one == 2 && two == 1) tot+=1;
        else if(two == 2 && one == 1) tot +=1;
        else if(two == 2 && one == 0)
        {
            if(b1 == 0 && b >= 3) tot++;
            if(g1 == 0 && g >= 3) tot++;
            if(r1 == 0 && r >= 3) tot++;
        }
        cout << tot << "\n";
    }

    return 0;
}
