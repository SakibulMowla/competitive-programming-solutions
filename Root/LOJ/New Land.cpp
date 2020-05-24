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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ  2010
#define SZ1 4100

#define left node<<1, b, mid
#define riht (node<<1)|1, mid+1, e

int arr[SZ];
int minim[SZ1];
int indx[SZ1];
int n, m;

void build(int node, int b, int e){
    if(b == e){
        minim[node] = arr[b];
        indx[node] = b;
        return;
    }

    int mid = (b + e) >> 1;

    build(left);
    build(riht);

    if(minim[node<<1] < minim[(node<<1)|1]){
        minim[node] = minim[node<<1];
        indx[node] = indx[node<<1];
    }
    else{
        minim[node] = minim[(node<<1)|1];
        indx[node] = indx[(node<<1)|1];
    }

    return;
}

int glo_minim, glo_indx, tmp;

void query(int node, int b, int e, int f, int t){
    if(b>=f && e<=t){
        if(minim[node] < glo_minim){
            glo_minim = minim[node];
            glo_indx = indx[node];
        }
        return;
    }

    int mid = (b + e) >> 1;

    if(f <= mid) query(left, f, t);
    if(t > mid) query(riht, f, t);

    return;
}

void solve(int strt, int end){
    if(strt > end) return;
    if(strt == end) {
        tmp = max(tmp, arr[strt]);
        return;
    }

    glo_minim = inf;

    query(1, 1, m, strt, end);

    tmp = max(tmp, glo_minim*(end-strt+1));

    solve(strt, glo_indx-1);
    solve(glo_indx+1, end);
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, t, i, j, ans;
    char s[SZ];

    RD(t);

    while(t--) {
        RD(n, m);

        memset(arr, 0, sizeof(int)*(m+5));
        ans = 0;

        REP1(i, 1, n){
            scanf("%s",s+1);
            REP1(j, 1, m){
                if(s[j] == '1') arr[j] = 0;
                else arr[j]++;
            }

            tmp = 0;
            build(1, 1, m);
            solve(1, m);
            ans = max(ans, tmp);
        }

        printf("Case %d: %d\n",++test, ans);
    }


    return 0;
}















