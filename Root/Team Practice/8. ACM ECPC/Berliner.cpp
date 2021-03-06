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
#include <assert.h>
#include <bitset>


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
const int inf = 1;
const ll mod = 1LL;

#define SZ  103

int flag[SZ][SZ][SZ];

queue <int> Q;

inline bool chk(int n)
{
    return (n>=0 && n <=102);
}

inline bool chk2(int x, int y, int z)
{
    return ( chk(x) && chk(y) && chk(z) && flag[x][y][z] == 1 );
}

inline bool chk3(int x, int y, int z)
{
    return ( chk(x) && chk(y) && chk(z) );
}

pii BFS()
{
    while(!Q.empty()) Q.pop();
    Q.push(0); Q.push(0); Q.push(0);
    pii ret = MP(0, 0);

    while(!Q.empty())
    {
        int x = Q.front(); Q.pop();
        int y = Q.front(); Q.pop();
        int z = Q.front(); Q.pop();
        if(flag[x][y][z] == 0)
        {
            flag[x][y][z] = 2;
            ret.X++;
            if(chk3(x+1, y, z)) {Q.push(x+1); Q.push(y); Q.push(z);}
            if(chk3(x-1, y, z)) {Q.push(x-1); Q.push(y); Q.push(z);}
            if(chk3(x, y+1, z)) {Q.push(x); Q.push(y+1); Q.push(z);}
            if(chk3(x, y-1, z)) {Q.push(x); Q.push(y-1); Q.push(z);}
            if(chk3(x, y, z+1)) {Q.push(x); Q.push(y); Q.push(z+1);}
            if(chk3(x, y, z-1)) {Q.push(x); Q.push(y); Q.push(z-1);}
            if(chk2(x+1, y, z) || chk2(x-1, y, z) || chk2(x, y+1, z) || chk2(x, y-1, z) || chk2(x, y, z+1) || chk2(x, y, z-1)) ret.Y++;
        }
    }

    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test = 0, t;

    scanf("%d", &t);

    while(t--)
    {
        mem(flag, 0);

        int n;
        scanf("%d", &n);
        int N = n;

        while(n--)
        {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            flag[x+1][y+1][z+1] = 1;
        }

        pii ret = BFS();

        printf("Case %d:\njam = %d\nsugar = %d\n", ++test, 103*103*103 - ret.X - N, ret.Y);
    }

    return 0;
}













