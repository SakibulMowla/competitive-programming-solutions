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

typedef unsigned long long ll;

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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 110

char arr[SZ];
ll dp[SZ][SZ];

ll solve(int from, int tooo){
    ll &ret = dp[from][tooo];
    if(ret != -1) return ret;

    if(from == tooo) return ret = (arr[from]-'0');
    else if(from + 2 == tooo) return ret = arr[from+1] == '+' ? arr[from]-'0'+arr[tooo]-'0' : (arr[from]-'0')*(arr[tooo]-'0');

    int i;
    ret = 0;

    for(i=from;i<tooo;i+=2)
        ret = max(ret, arr[i+1] == '+' ? solve(from, i) + solve(i+2, tooo) : solve(from, i) * solve(i+2, tooo));

    return ret;
}

ll solve1(int from, int tooo){
    ll &ret = dp[from][tooo];
    if(ret != -1) return ret;

    if(from == tooo) return ret = (arr[from]-'0');
    else if(from + 2 == tooo) return ret = arr[from+1] == '+' ? arr[from]-'0'+arr[tooo]-'0' : (arr[from]-'0')*(arr[tooo]-'0');

    int i;
    ret = arr[from+1] == '+' ? solve1(from, from) + solve1(from+2, tooo) : solve1(from, from) * solve1(from+2, tooo);

    for(i=from+2;i<tooo;i+=2)
        ret = min(ret, arr[i+1] == '+' ? solve1(from, i) + solve1(i+2, tooo) : solve1(from, i) * solve1(i+2, tooo));

    return ret;
}


int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("myout.txt", "w", stdout);
    #endif

    int t, i, len;

    scanf("%d",&t);

    while(t--){
        scanf("%s",arr);
        len = strlen(arr);
        mem(dp, -1);
        printf("%llu",solve(0, len-1));
        mem(dp, -1);
        printf(" %llu\n",solve1(0, len-1));
    }


    return 0;
}
















