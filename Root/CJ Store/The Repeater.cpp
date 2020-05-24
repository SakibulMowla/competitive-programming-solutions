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

#define SZ  110

struct data{
    string ss;
    int cnt[SZ];
};

data arr[SZ];

int maxim[SZ], minim[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, l, t, i, j, k, n, m, f, res, ans;
    string str;

    RD(t);

    while(t--){
        RD(n);
        f = 1;

        REP(i, n){
            cin >> str;
            k = sz(str);
            arr[i].ss = "";

            for(j=0; j<k; j++){
                l = sz(arr[i].ss);
                if(l && arr[i].ss[l-1] == str[j]){
                    arr[i].cnt[l-1]++;
                }
                else{
                    arr[i].ss += str[j];
                    arr[i].cnt[l] = 1;
                }
            }
        }

        str =  arr[0].ss;

        for(i=1; i<n; i++){
            if(arr[i].ss != str){
                f = 0;
                break;
            }
        }

        if(f == 0){
            printf("Case #%d: Fegla Won\n",++test);
            continue;
        }

        k = sz(arr[0].ss);

        REP(i, k) {
            maxim[i] = minim[i] = arr[0].cnt[i];
        }

        for(i=1; i<n; i++){
            for(j=0; j<k; j++){
                maxim[j] = max(maxim[j], arr[i].cnt[j]);
                minim[j] = min(minim[j], arr[i].cnt[j]);
            }
        }

        ans = 0;

//        printf("k = %d\n",k);
//        REP(i, k){
//            printf("%d %d\n",maxim[i],minim[i]);
//        }

        REP(i, k){
            res = 1e9;
            for(j=minim[i]; j<=maxim[i]; j++){
                int tmp = 0;
                for(l=0; l<n; l++){
                    tmp += abs(arr[l].cnt[i]-j);
                }
                res = min(res, tmp);
            }
//            printf("i = %d res = %d\n",i,res);
            ans += res;
        }

        printf("Case #%d: %d\n",++test,ans);
    }

    return 0;
}





/*

5
2
mmaw
maw

*/








