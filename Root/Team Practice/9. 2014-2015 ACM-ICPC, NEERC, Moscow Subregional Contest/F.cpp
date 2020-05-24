#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

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


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    double xa, ya, xb, yb, xc, yc;

    while(scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc) == 6)
    {
//        { ///Alex
            double d, v;
            scanf("%lf %lf", &d, &v);
            double d1 = d * 60.0;
            double dist = sqrt( (xa-xc)*(xa-xc) + (ya-yc)*(ya-yc) ) + sqrt( (xb-xc)*(xb-xc) + (yb-yc)*(yb-yc) );
            d1 += (dist/v)*60.0*60.0;
//        }
//        { ///Dmitry
            double dep1, dep2, dur1, dur2;
            scanf("%lf:%lf %lf:%lf", &dep1, &dep2, &dur1, &dur2);
            double d2 = (dep1-9)*60*60 + dep2*60 + dur1*60*60 + dur2*60;
//        }
//        { /// Petr
            double w;
            scanf("%lf", &w);
            dist = sqrt( (xa-xb)*(xa-xb) + (ya-yb)*(ya-yb) );
            double d3 = (dist/w)*60*60;
            if((xc-xa)*(ya-yb) == (xa-xb)*(yc-ya)) d3 += d*60;
//        }

        if(d1 < d2 && d1 < d3) printf("Alex\n");
        else if(d2 < d1 && d2 < d3) printf("Dmitry\n");
        else printf("Petr\n");
    }

    return 0;
}












