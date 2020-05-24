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

ll x[] = {0,0,-1,1};//4-way
ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

ll n, r, c;
ll col[SZ][SZ];
queue <int> Q;

void BFS()
{
    memset(col,-1,sizeof(col));
    while(!Q.empty()) Q.pop();

    ll i, j, k, u, v, now, next, cnt, cclr, p, q;

    Q.push(0);
    Q.push(0);
    cclr = 0;

    col[0][0] = cclr;
    next = 1;
    now = 1;
    cnt = 0;

    if(cnt == n-1)
        next = (r*c) -( (n*(n-1))/2 );

    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        v = Q.front();
        Q.pop();
        for(i=0; i<4; i++)
        {
            p = u + x[i];
            q = v + y[i];
            if(p>=0 && q>=0 && p < r && q < c && col[p][q] == -1)
            {
                if(now == next)
                {
                    printf("now = %lld %lld %lld\n",now,p,q);
                    cnt++;
                    if(cnt == n-1)
                        next = (r*c) -( (n*(n-1))/2 );
                    else
                        next = next + 1;
                    now=0;
                    cclr++;
                    cclr %= 26;
                    while(!Q.empty()) Q.pop();
                    Q.push(p);
                    Q.push(q);
                    col[p][q] = cclr;
                    now++;
                    goto here;
                }
                else
                {
                    Q.push(p);
                    Q.push(q);
                    col[p][q] = cclr;
                    now++;
                }
            }
        }
        here:;
    }
}

//%I64d
int main()
{
    double d;
    ll i, j;

    while(scanf("%lld %lld",&r,&c) == 2)
    {
        d = (double)((sqrt(1+(double)(8*r*c))-1)/2);
        n = d;
        BFS();
        printf("%lld\n",n);
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                printf("%c",(char)col[i][j]+'A');
            }
            printf("\n");
        }
    }

    return 0;
}
