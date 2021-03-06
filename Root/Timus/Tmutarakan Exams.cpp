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

#define SZ 55

ll nCr[30][30];

void pre(){
    int i, j;
    for(i=0; i<=25; i++)
        for(j=0; j<=i; j++)
            if(i == j) nCr[i][j] = 1LL;
            else if(j == 1) nCr[i][j] = (ll)i;
            else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
    return;
}

bool arr[SZ];
vector <int> prime;
int K;

void sieve(){
    int i, j, k;

    k = sqrt(55);

    for(i=3; i<=k; i+=2)
        if(arr[i] == 0)
            for(j=i*i; j<55; j+=i+i)
                arr[j] = 1;

    prime.pb(2);

    for(i=3; i<=50; i+=2)
        if(arr[i] == 0)
            prime.pb(i);

    K = sz(prime);

    return;
}

int factors[55];

void bctk(int num, int indx, int primes){
    factors[num] = primes;

    int i;
    for(i=indx; i<K; i++){
        if(num*prime[i] > 50) break;
        bctk(num*prime[i], i+1, primes+1);
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    pre();
    sieve();
    bctk(1, 0, 2);

    int i, j, k, s;
    ll ans;

    scanf("%d %d",&k,&s);

    ans = 0LL;

    for(i=2; i<=s; i++)
        if(factors[i]){
            j = s/i;
            if(j < k) continue;

//            printf("i = %d j = %d f = %d\n",i,j,factors[i]);
//            printf("nCr = %lld\n",nCr[j][k]);

            if(factors[i]&1) ans += nCr[j][k];
            else ans -= nCr[j][k];
        }

    if(ans > 10000LL)
        ans = 10000LL;

    printf("%lld\n",ans);

    return 0;
}














