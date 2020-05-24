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
    ll x, y;
};

data arr[110];

ll n, dp[110];
bool col[110];
ll a, b, c, d;
ll a1, b1, c1, d1;
ll to;

bool found;

//ll solve(ll p)
//{
//    col[p] = 1;
//    if(found) return 1;
//
//    ll i;
//    ll &ret = dp[p];
//    if(ret != -1) return ret;
//    ret = 0;
//
//    for(i=1; i<n; i++)
//    {
//        if(i == p) continue;
//        a1 = arr[p].x;
//        b1 = arr[p].y;
//        c1 = arr[i].x;
//        d1 = arr[i].y;
//        if(!col[i])
//            if( (c1 < a1 && a1 < d1) || ( c1 < b1 && b1 < d1 ) )
//            {
//                if(i == to)
//                {
//                    found = 1;
//                    return ret = 1;
//                }
//                ret = max(ret, solve(i));
//            }
//    }
//
//    return ret;
//}

//ll search(ll p,ll q)
//{
//    if( (c < a && a < d) || ( c < b && b < d ) )
//        return 1;
//    return 0;
//}

vector <ll> adj[110];

void solve(ll a,ll b)
{
    if(a == b)
    {
        found = 1;
        return;
    }
    col[a] = 1;

    ll i,j,k;

    k = sz(adj[a]);

    for(i=0; i<k; i++)
    {
        j = adj[a][i];
        if(!col[j]) solve(j,b);
    }
}

//%I64d
int main()
{
    ll q, i, j, k, a, b, p;

    while(scanf("%I64d",&q) == 1)
    {
        n = 1;
        while(q--)
        {
            scanf("%I64d %I64d %I64d",&k,&i,&j);

            if(k == 1)
            {
                arr[n].x = i;
                arr[n++].y = j;
                c = i;
                d = j;
                for(p=1; p<n-1; p++)
                {
                    a = arr[p].x;
                    b = arr[p].y;
                    if( (c < a && a < d) || ( c < b && b < d ) )
                        adj[p].push_back(n-1);
                    if( (a < c && c < b) || ( a < d && d < b ) )
                        adj[n-1].push_back(p);
                }
            }
            else if(k == 2)
            {
//                a = arr[i].x;
//                b = arr[i].y;
//                c = arr[j].x;
//                d = arr[j].y;
                found = 0;
//                to = j;
//                memset(dp, -1, sizeof(dp));
                memset(col, 0, sizeof(col));
                solve(i,j);
                if( found ) printf("YES\n");
                else printf("NO\n");
            }
        }
    }

    return 0;
}

