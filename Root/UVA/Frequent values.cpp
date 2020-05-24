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
//
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

#define SZ  100010
#define SZ1 262150


#define left node<<1, b, mid
#define riht node<<1|1, mid+1, e


struct data{
    int b, e, cnt;
};


data info[SZ];
int arr[SZ];
int tree[SZ1];


class Problem {
public:
    int i, j, k, pos, n, q, ans;
    Problem();
    void take_input();
    void process();
    void solve();
    void build(int,int,int);
    int query(int,int,int,int,int);
};


Problem::Problem() {
}


void Problem::take_input() {
    REP1(i, 1, n) RD(arr[i]);
}


void Problem::process(){
    for(i=1;i<=n;i++){
        pos = i;
        while(pos+1<=n && arr[pos+1] == arr[pos]) pos++;
        k = pos-i+1;
        j = i;
        while(j<=pos){
            info[j].b = i;
            info[j].e = pos;
            info[j].cnt = k;
            j++;
        }
        i = pos;
    }
}


void Problem::solve(){
    build(1, 1, n);

    while(q--){
        RD(i, j);
//        inp(i);inp(j);
        ans = max(min(info[i].e, j)-i+1, j-max(info[j].b, i)+1);
        if(info[i].e+1 <= info[j].b-1)
            ans = max(ans, query(1, 1, n, info[i].e+1, info[j].b-1));
        PR(ans);
    }
}


void Problem::build(int node, int b, int e){
    if(b == e){
        tree[node] = info[e].cnt;
        return;
    }

    int mid = (b + e) >> 1;

    build(left);
    build(riht);

    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}


int Problem::query(int node, int b, int e, int f, int t){
    if(b>=f && e<=t)
        return tree[node];

    int mid = (b + e) >> 1, ret = 0;

    if(f <= mid) ret = query(left, f, t);
    if(t > mid) ret = max(ret, query(riht, f, t));

    return ret;
}


int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    Problem Frequent_values;

    while(scanf("%d",&Frequent_values.n) == 1 && Frequent_values.n){
        scanf("%d",&Frequent_values.q);
        Frequent_values.take_input();
        Frequent_values.process();
        Frequent_values.solve();
    }

    return 0;
}












