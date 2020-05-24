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

template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
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

#define SZ  5010
#define SZ1 100010

bool arr[SZ1];
vector <int> prime;
int num[SZ];
map <int , int> mp;
int cum[SZ];

void sieve(){
    int i, j, k;

    k = sqrt(SZ1);
    for(i=3;i<=k;i+=2)
        if(!arr[i])
            for(j=i*i;j<SZ1;j+=i+i)
                arr[j] = 1;
    prime.pb(2);
    for(i=3;i<SZ1;i+=2)
        if(!arr[i])
            prime.pb(i);
//    REP(i, 25)
//        PR(prime[i]);
}

vector <int> v;

int fact(int n){
    int i, j, k, m = n;

    clr(v);
    k = sz(prime);

    for(i=0; i<k && (ll)( (ll)prime[i]*(ll)prime[i] ) <= (ll)n; i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                v.pb(prime[i]);
                n /= prime[i];
            }
        }
    }

    if(n != 1){
        v.pb(n);
    }

    k = sz(v);
    j = 0;

    for(i=0;i<k;i++){
        if(mp.find(v[i]) == mp.end()) j++;
        else j--;
    }

    return j;
}

int factorize(int n){
    int i, j, k, m = n;

    k = sz(prime);
    j = 0;

    for(i=0; i<k && (ll)( (ll)prime[i]*(ll)prime[i] ) <= (ll)n; i++){
        if(n % prime[i] == 0){
            while(n % prime[i] == 0){
                if(mp.find(prime[i]) != mp.end()) j--;
                else j++;
                n /= prime[i];
            }
        }
    }

    if(n != 1){
        if(mp.find(n) != mp.end()) j--;
        else j++;
    }

    return j;
}


int val[SZ];

int solve(int n, int m){
    int i, j, k;

    val[n+1] = 1;
    for(i=n;i>=1;i--){
        cum[i] /= val[i+1];
        val[i] = val[i+1];
        k = factorize(cum[i]);
        if(k < 0) val[i] *= cum[i];
        num[i] /= val[i];
//        printf("val[%d] = %d\n",i,val[i]);
    }

    k = 0;

    REP1(i, 1, n)
        k += fact(num[i]);

    return k;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();
    int n, m, i, j, k;

    while(scanf("%d %d",&n,&m) == 2){
        clr(mp);

        REP1(i, 1, n) {
            RD(num[i]);
            if(i == 1) cum[i] = num[i];
            else cum[i] = gcd(cum[i-1], num[i]);
        }
        REP1(i, 1, m) {
            RD(j);
            mp[j] = 1;
        }

        PR(solve(n, m));
    }



    return 0;
}











