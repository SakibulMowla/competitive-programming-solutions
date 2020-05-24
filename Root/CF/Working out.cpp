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

#define SZ 1010

ll dp1[SZ][SZ], dp2[SZ][SZ], dp3[SZ][SZ], dp4[SZ][SZ];
ll arr[SZ][SZ];
int row, col;

int x1[] = {-1,0};
int yy1[] = {0,-1};

ll solve1(int a, int b){
//    printf("1 %d %d\n",a,b);
    if(a==1 && b==1) return arr[a][b];

    ll &ret = dp1[a][b];
    if(~ret) return ret;

    int i, u, v;
    ret = 0LL;

    for(i=0; i<2; i++){
        u = a + x1[i];
        v = b + yy1[i];
        if(u>=1 && u<=row && v>=1 && v<=col)
            ret = max(ret, arr[a][b]+solve1(u, v));
    }

    return ret;
}

int x2[] = {-1,0};
int y2[] = {0,1};

ll solve2(int a, int b){
//    printf("2 %d %d\n",a,b);
    if(a==1 && b==col) return arr[a][b];

    ll &ret = dp2[a][b];
    if(~ret) return ret;

    int i, u, v;
    ret = 0LL;

    for(i=0; i<2; i++){
        u = a + x2[i];
        v = b + y2[i];
        if(u>=1 && u<=row && v>=1 && v<=col)
            ret = max(ret, arr[a][b]+solve2(u, v));
    }

    return ret;
}

int x3[] = {1,0};
int y3[] = {0,-1};

ll solve3(int a, int b){
//    printf("3 %d %d\n",a,b);
    if(a==row && b==1) return arr[a][b];

    ll &ret = dp3[a][b];
    if(~ret) return ret;

    int i, u, v;
    ret = 0LL;

    for(i=0; i<2; i++){
        u = a + x3[i];
        v = b + y3[i];
        if(u>=1 && u<=row && v>=1 && v<=col)
            ret = max(ret, arr[a][b]+solve3(u, v));
    }

    return ret;
}

int x4[] = {0,1};
int y4[] = {1,0};

ll solve4(int a, int b){
//    printf("4 %d %d\n",a,b);
    if(a==row && b==col) return arr[a][b];

    ll &ret = dp4[a][b];
    if(~ret) return ret;

    int i, u, v;
    ret = 0LL;

    for(i=0; i<2; i++){
        u = a + x4[i];
        v = b + y4[i];
        if(u>=1 && u<=row && v>=1 && v<=col)
            ret = max(ret, arr[a][b]+solve4(u, v));
    }

    return ret;
}

int v1[] = {1, 4};
int v2[] = {1, 2};
int v3[] = {3, 4};
int v4[] = {2, 3};

int fun(int a, int b, int t){
    if(t==1) a -= 1;
    if(t==2) b += 1;
    if(t==3) a += 1;
    if(t==4) b -= 1;

    if(a<1 || a>row || b<1 || b>col) return 0;
    return 1;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    ll ans, tmp;
    int i, j, p, q, r, s, a, b, t;

    while(scanf("%d %d",&row,&col) == 2){
        ans = 0LL;
        REP1(i, 1, row) REP1(j, 1, col) RD(arr[i][j]);

        mem(dp1, -1);
        mem(dp2, -1);
        mem(dp3, -1);
        mem(dp4, -1);

        REP1(i, 1, row) REP1(j, 1, col) {
//            ans = max(ans, solve1(i, j) + solve2(i, j) + solve3(i, j) + solve4(i, j) - 4LL*arr[i][j]);
//            if(ans == 900) printf("%d %d\n",i,j);
            for(p=0;p<2;p++) for(q=0;q<2;q++) for(r=0;r<2;r++) for(s=0;s<2;s++) {
                if(v1[p]==v2[q] || v1[p]==v3[r] || v1[p]==v4[s] || v2[q]==v3[r] || v2[q]==v4[s] || v3[r]==v4[s]) continue;
                if(!fun(i, j, v1[p])) continue;
                if(!fun(i, j, v2[q])) continue;
                if(!fun(i, j, v3[r])) continue;
                if(!fun(i, j, v4[s])) continue;

                tmp = 0LL;

                a = i;
                b = j;
                t = v1[p];
                if(t==1) a -= 1;
                if(t==2) b += 1;
                if(t==3) a += 1;
                if(t==4) b -= 1;

                tmp += solve1(a, b);

                a = i;
                b = j;
                t = v2[q];
                if(t==1) a -= 1;
                if(t==2) b += 1;
                if(t==3) a += 1;
                if(t==4) b -= 1;

                tmp += solve2(a, b);

                a = i;
                b = j;
                t = v3[r];
                if(t==1) a -= 1;
                if(t==2) b += 1;
                if(t==3) a += 1;
                if(t==4) b -= 1;

                tmp += solve3(a, b);

                a = i;
                b = j;
                t = v4[s];
                if(t==1) a -= 1;
                if(t==2) b += 1;
                if(t==3) a += 1;
                if(t==4) b -= 1;

                tmp += solve4(a, b);

                ans = max(ans, tmp);
//                if(ans == 511) printf("%d %d\n",i,j);
            }
        }

//        ans = solve1(1, 3) + solve2(1, 3) + solve3(1, 3) + solve4(1, 3) - 4LL*arr[1][3];

        PR(ans);

        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}






