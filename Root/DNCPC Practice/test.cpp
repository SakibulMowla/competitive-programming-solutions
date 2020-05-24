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
ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

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
const ll mod = 1000000007LL;

#define SZ 110

ll brute[SZ], dynamic[SZ];

ll ff(int n){
    int i;
    ll ret = 0;
    for(i=0; i<=n; i++){
        ret = (ret + (BigMod(25, i, mod)*BigMod(26, n-i, mod)) % mod ) % mod;
    }
    return ret;
}

ll bigmod(int n){
    ll ret = (BigMod(26, n+1, mod) - BigMod(25, n+1, mod) + mod) % mod;
    return ret;
}

ll BigMod(int n){
    if(n == 0) return 1LL;

    ll ans = 0LL, ret;

    if(n%2 == 0){
        ret = BigMod(n/2 - 1);
        ans = ( BigMod(25, n-1, mod) * ret ) % mod;
        ans = (ans + ( BigMod(25, n/2, mod) * BigMod(26, n/2, mod) ) % mod ) % mod;
        ans = ans + (ret * BigMod(26, n-1, mod)) % mod;
    }
    else{
        ret = BigMod(n/2);
        ans = ( BigMod(25, (n+1)/2, mod) * ret ) % mod;
        ans = ans + (ret * BigMod(26, (n+1)/2, mod)) % mod;
    }

    return ans;
}

int main(){
    #if defined JESI
//        freopen("1.txt", "r", stdin);
        freopen("1.txt", "w", stdout);
    #endif // defined

    int i, test, n, m, k;

    test = 10;

    printf("%d\n",test);

    while(test--){
        k = rand() % 101;
        n = rand() % (1000000000+1);
        m = rand() % 11;
        if(!n) n++;
        if(!m) m++;
        if(!k) k++;

        for(i=0; i<k; i++)
            printf("%c",rand()%26+'a');
        puts("");

        printf("%d %d\n",m,n);
    }

    return 0;
}
