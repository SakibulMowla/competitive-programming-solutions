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

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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
const ll inf = 1;
const ll mod = 1LL;

#define SZ 110

struct data{
    int a, b, c, d;
    data(){}
    data(int w, int x, int y, int z){
        a = w, b = x, c = y, d = z;
    }
};

vector <data> v;
int row, col, minim, rr, cc;

char arr[SZ][SZ];

void bctk(int p, int q, int left){
//    printf("%d %d\n",p,q);
    int np, nq, tmp, tmpp, tmpq;
    tmp = min(row-p, col-q);
    np = p + tmp;
    nq = q + tmp;
    v.pb(data(p, q, np, nq));
    if(np==row && nq==col) return;

    left -= (np-p+1)*(nq-q+1);

    if(np==row) tmpp = p, tmpq = nq+1;
    else tmpp = np+1, tmpq = q;

    if(left >= (tmp*tmp)){
        if(rr == 1){
            for(int i=tmpq; i<=col; i++){
//                printf("rr %d\n",i);
                v.pb(data(tmpp, i, tmpp, i));
                left--;
            }
            tmpp++;
        }
        if(cc == 1){
            for(int i=tmpp; i<=row; i++){
//                printf("cc %d\n",i);
                v.pb(data(i, tmpq, i, tmpq));
                left--;
            }
            tmpq++;
        }
    }

    if(tmpp>row || tmpq>col) return;

    bctk(tmpp, tmpq, left);
}

void paint(int a, int b, int c, int d, char ch){
//    printf("%d %d %d %d %c\n",a,b,c,d,ch);
    int i, j;
    for(i=a; i<=c; i++) for(j=b; j<=d; j++) arr[i][j] = ch;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, tmp;
    int f[4];
    char ch;

    while(scanf("%d %d",&row,&col) == 2){
        minim = min(row, col);
        clr(v);
        rr = cc = 0;
        if(row < col) cc = 1;
        else rr = 1;
        bctk(1, 1, row*col);

        paint(v[0].a, v[0].b, v[0].c, v[0].d, 'A');

        k = sz(v);
        for(i=1; i<k; i++){
            f[0] = f[1] = f[2] = 0;
            if(v[i].a-1 >= 1){
                if(arr[v[i].a-1][v[i].b] == 'A') f[0] = 1;
                else if(arr[v[i].a-1][v[i].b] == 'B') f[1] = 1;
                else if(arr[v[i].a-1][v[i].b] == 'C') f[2] = 1;
            }
            if(v[i].b-1 >= 1){
                if(arr[v[i].a][v[i].b-1] == 'A') f[0] = 1;
                else if(arr[v[i].a][v[i].b-1] == 'B') f[1] = 1;
                else if(arr[v[i].a][v[i].b-1] == 'C') f[2] = 1;
            }
            if(f[0] == 0) ch = 'A';
            else if(f[1] == 0) ch = 'B';
            else if(f[2] == 0) ch = 'C';
            paint(v[i].a, v[i].b, v[i].c, v[i].d, ch);
        }

        REP1(i, 1, row) {
            REP1(j, 1, col)
                printf("%c",arr[i][j]);
            puts("");
        }

        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}


/*

2 5
AABBA
AABBC

AABAA
AACAA

*/



