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
typedef pair<int,int> pii;

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

#define SZ 50
#define eps 1e-8
const ll inf = 1LL<<28;
const ll mod = 1LL;

struct data
{
    double x, y;
};

data point[SZ];
int n, space, side;

void kopa(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
    double x,y,dx,dy,d,r,r1,dx1,dy1,dx4,dy4;

    dx1 = (x3-x1)*(y1-y2);
    dx4 = (x1-x2)*(y3-y1);

    if(dx1 == dx4)
    {
        space++;
        return;
    }

    d=(x1-x2)*(y1-y3)-(x1-x3)*(y1-y2);
    dx=((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(y1-y3)/2)-((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(y1-y2)/2);
    dy=((pow(x1,2)-pow(x3,2)+pow(y1,2)-pow(y3,2))*(x1-x2)/2)-((pow(x1,2)-pow(x2,2)+pow(y1,2)-pow(y2,2))*(x1-x3)/2);
    x=dx/d;
//    x=dx;
    y=dy/d;
//    y=dy;
//    r=pow(x-x1,2)+pow(y-y1,2);
    dx1 = d*x1;
    dy1 = d*y1;
    dx4 = d*x4;
    dy4 = d*y4;
    r=pow(dx-dx1,2)+pow(dy-dy1,2);
//    r1=pow(x-x4,2)+pow(y-y4,2);
    r1=pow(dx-dx4,2)+pow(dy-dy4,2);
//    printf("%lf %lf r1 = %lf r = %lf\n",x,y,r1,r);
//    printf("%lf %lf\n",r,r1);
//    if(r <= 1000000 && r >= 0)
        if(r1 <= r)
            side++;
    space++;
}

void process(int a,int b,int c)
{
    int i;
    for(i=1; i<=n; i++)
        if(i!=a && i!=b && i!=c)
            kopa(point[a].x,point[a].y,point[b].x,point[b].y,point[c].x,point[c].y,point[i].x,point[i].y);
}

//%I64d
int main()
{
    int i, j, k, t;
    double d;
    scanf("%d",&t);

    while(t--)
    {
        side = space = 0;
        scanf("%d",&n);
        for(i=1; i<=n; i++)
            scanf("%lf %lf",&point[i].x,&point[i].y);
        for(i=1; i<=n; i++)
            for(j=i+1; j<=n; j++)
                for(k=j+1; k<=n; k++)
                    process(i, j, k);
        d = (double)side/(double)space;
        printf("%.12lf\n",d);
//        cout << d << "\n";
    }

    return 0;
}
