#include <stdio.h>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iostream>
#include <algorithm>
#include <deque>


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

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }


typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const double inf = 2e9 + 10;
const ll mod = 1LL;
const double EPS = 1e-8;

#define SZ 100010

struct data {
    int x, y;
};

data lft[SZ], rht[SZ], cam[SZ];

void read(data arr[], int &n) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d %d", &arr[i].x, &arr[i].y);
    return;
}

double find_x(data a, data b, int y) {
    double x;
    x = (double)(y - a.y) * (a.x - b.x) / (a.y - b.y) + (double)a.x;
    return x;
}

int main() {
    int i, j, k, n, m, c, y, p;
    vector <double> v;
    double maxim, tmp;

    read(lft, n);
    read(rht, m);
    read(cam, c);
    lft[n].x = lft[n].y = inf;
    rht[m].x = rht[m].y = inf;
    cam[c].x = cam[c].y = inf;

    k = 0;
    while(cam[k].y < lft[0].y) k++;

    maxim = 1e17;

    for(i = 0, j = 0; i < n || j < m; ) {
        y = min(cam[k].y, min(lft[i].y, rht[j].y));
        clr(v);

        if(lft[i].y == y)
            v.pb( (double)lft[i++].x );
        else
            v.pb( find_x(lft[i-1], lft[i], y) );

        if(rht[j].y == y)
            v.pb( (double)rht[j++].x );
        else
            v.pb( find_x(rht[j-1], rht[j], y) );

        while(cam[k].y == y) {
            if(cam[k].x >= v[0] - EPS && cam[k].x <= v[1] + EPS)
                v.pb( (double)cam[k].x );
            k++;
        }

        sort(v.begin(), v.end());

        tmp = 0.0;
        for(p = 1; p < sz(v); p++) {
            tmp = max(tmp, v[p] - v[p-1]);
        }

        maxim = min(maxim, tmp);
    }

    printf("%.10lf\n", maxim);

    return 0;
}
