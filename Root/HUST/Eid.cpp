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
inline ll BigMod(ll B,ll P){     ll R=1; while(P>0)      {if(P%2==1){R=(R*B);}P/=2;B=(B*B);} return R;} /// (B^P)%M

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

#define SZ 10010

bool arr[SZ];
int prime[SZ];
int cnt[SZ];
map <int , int> mp;
int nprime;

void sieve() {
    int i, j, k;

    k = sqrt(SZ);

    for(i=3;i<=k;i+=2)
        if(!arr[i])
            for(j=i*i;j<SZ;j+=i+i)
                arr[j] = 1;

    nprime = 0;
    prime[nprime++] = 2;
    mp[2] = 0;

    for(i=3;i<SZ;i+=2)
        if(!arr[i])
            prime[nprime++] = i, mp[i] = nprime-1;
}

void factorize(int n){
    int i, j, k;

    for(i=0;i<nprime && prime[i]*prime[i]<=n;i++){
        if(n%prime[i] == 0){
            j = 0;
            while(n%prime[i] == 0){
                j++;
                n /= prime[i];
            }
            cnt[i] = max(cnt[i], j);
        }
    }

    if(n != 1){
        cnt[ mp[n] ] = max(cnt[ mp[n] ], 1);
    }
}

inline string Multiplication(string &a,int k) {
    string ans;
    int i,sum,carry=0, l;

    l = sz(a);

    for(i=l-1;i>=0;i--) {
        sum=(a[i]-'0')*k+carry;
        carry=sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry) {
        ans+=(carry%10)+'0';
        carry/=10;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt","r",stdin);
//        freopen("2.txt","w",stdout);
    #endif // defined

    sieve();
    int test=0, t, n, i, j;
    string ans;

    scanf("%d",&t);

    while(t--){
        mem(cnt, 0);
        scanf("%d",&n);

        while(n--){
            scanf("%d",&i);
            factorize(i);
        }

        ans = "1";

        for(i=0;i<nprime;i++)
            if(cnt[i])
                ans = Multiplication(ans, BigMod(prime[i], cnt[i]));

        printf("Case %d: %s\n",++test,ans.c_str());
    }


    return 0;
}













