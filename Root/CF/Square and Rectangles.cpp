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

struct data
{
    int x1, x2, y1, y2;
};

data arr[10];
vector <data> info;

bool chk()
{
    int i, j, k, n, px, qx, py, qy;
    ll area;

    n = sz(info);
    px = py = qx = qy = 0;
    px = py = 1<<28;

    for(i=0;i<n;i++)
    {
        px = min(px, info[i].x1);
        py = min(py, info[i].y1);
        qx = max(qx, info[i].x2);
        qy = max(qy, info[i].y2);
    }

    if(px-qx == py-qy)
    {
        area = (qx-px) * (qy-py);
        for(i=0;i<n;i++)
            area -= (ll)(info[i].x2-info[i].x1)*(info[i].y2-info[i].y1);
        if(area == 0) return 1;
        return 0;
    }

    return 0;
}

//%I64d
int main()
{
    int i, ans, n, lim;

    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<n;i++)
            scanf("%d %d %d %d",&arr[i].x1,&arr[i].y1,&arr[i].x2,&arr[i].y2);
        lim = 1<<n;

        ans = 0;
        info.clear();

        for(i=0;i<n;i++)
            info.push_back(arr[i]);

        if(chk() == 1)
            ans = 1;

        if(ans) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
