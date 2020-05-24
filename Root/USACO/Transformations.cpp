/*
ID: sakibul1
PROG: transform
LANG: C++
*/


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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%lld",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%lld%lld",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%lld\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

//inline void inp( int &n ){
//    n=0;
//    int ch=getchar_unlocked();int sign=1;
//    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
//    while(  ch >= '0' && ch <= '9' )
//            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
//    n=n*sign;
//}


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
const int inf = 1;
const ll mod = 1LL;

#define SZ  10

struct board
{
    int n;
    char b[SZ][SZ];
};

board read(int n)
{
    board b;
    int i, j;

    b.n = n;
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf(" %c",&b.b[i][j]);

    return b;
}

bool equal(board b, board c)
{
    int i, j;
    for(i=0; i<b.n; i++)
        for(j=0; j<b.n; j++)
            if(b.b[i][j] != c.b[i][j])
                return 0;
    return 1;
}

board shift90(board b)
{
    int i, j;
    board c = b;
    for(i=0; i<b.n; i++)
        for(j=0; j<b.n; j++)
            c.b[i][j] = b.b[b.n-1-j][i];
    return c;
}

void print(board b)
{
    int i, j;
    for(i=0; i<b.n; i++)
    {
        for(j=0;j<b.n; j++)
        {
            printf("%c",b.b[i][j]);
        }
        puts("");
    }
}

board reflect(board b)
{
    board c = b;
    int i, j;

    for(i=0; i<b.n; i++)
        for(j=0; j<b.n; j++)
            c.b[i][b.n-1-j] = b.b[i][j];

    return c;
}

int main() {
//        freopen("transform.in", "r", stdin);
//        freopen("transform.out", "w", stdout);

    int n;
    board bfr, aft;

    scanf("%d",&n);

    bfr = read(n);
    aft = read(n);

//    puts("------");
//    print(shift90(bfr));



    if(equal(aft, shift90(bfr))) printf("1\n");
    else if(equal(aft, shift90(shift90(bfr)))) printf("2\n");
    else if(equal(aft, shift90(shift90(shift90(bfr))))) printf("3\n");
    else if(equal(aft, reflect(bfr))) printf("4\n");
    else if(equal(aft, shift90(reflect(bfr))) || equal(aft, shift90(shift90(reflect(bfr)))) || equal(aft, shift90(shift90(shift90(reflect(bfr)))))) printf("5\n");
    else if(equal(aft, bfr)) printf("6\n");
    else printf("7\n");

    return 0;
}













