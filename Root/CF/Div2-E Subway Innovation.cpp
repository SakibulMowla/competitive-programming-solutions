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

void RD(int &x) {
    scanf("%d",&x);
}
void RD(ll &x) {
    scanf("%I64d",&x);
}
void RD(double &x) {
    scanf("%lf",&x);
}
void RD(int &x,int &y) {
    scanf("%d%d",&x,&y);
}
void RD(ll &x,ll &y) {
    scanf("%I64d%I64d",&x,&y);
}
void RD(double &x,double &y) {
    scanf("%lf%lf",&x,&y);
}
void RD(char *s) {
    scanf("%s",s);
}
void RD(char &s) {
    scanf("%c",&s);
}
void RD(string &s) {
    cin>>s;
}

void PR(int x) {
    printf("%d\n",x);
}
void PR(int x,int y) {
    printf("%d %d\n",x,y);
}
void PR(ll x) {
    printf("%I64d\n",x);
}
void PR(char x) {
    printf("%c\n",x);
}
void PR(char *x) {
    printf("%s\n",x);
}
void PR(string x) {
    cout<<x<<endl;
}

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 3*100010

struct data{
    ll d, num;
};

data arr[SZ];

bool comp(data a, data b){
    return a.d < b.d;
}

int main() {
    ll i, j , k, n, cum, cost, best, strt;

    while(scanf("%I64d",&n) == 1){
        REP1(i, 1, n) RD(arr[i].d), arr[i].num = i;
        RD(k);

        stable_sort(arr+1, arr+n+1, comp);

        strt = 1;
        cum = 0;
        cost = 0;

        REP1(i, 1, k) {
            cost += arr[i].d*(i-1) - cum;
            cum += arr[i].d;
        }

        best = cost;

        REP1(i, k+1, n) {
//            PR(i);
            cum -= arr[i-k].d;
            cost -= ( cum - arr[i-k].d * (k-1) );
            cost += ( arr[i].d * (k-1) - cum );
            cum += arr[i].d;

            if(cost < best){
                best = cost;
                strt = i-k+1;
            }
        }

        REP1(i, strt, strt+k-1)
            printf("%I64d ",arr[i].num);
        puts("");
    }

    return 0;
}
















