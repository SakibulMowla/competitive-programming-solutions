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

#define SZ 25

ll solve_big(int, int);
ll solve_small(int, int);
void print_big(int, int, ll, int);
void print_small(int, int, ll, int);

ll dp_small[SZ][SZ], dp_big[SZ][SZ];

char mp[SZ], arr[SZ];

ll solve_small(int a, int b){
    if(a == 1 && b == 0) return dp_small[a][b] = 1LL;

    ll &ret = dp_small[a][b];
    if(~ret) return ret;

    int i;
    ret = 0LL;

    for(i=1; i<=a; i++){
        ret += solve_big(i-1, b+a-i);
    }

    return ret;
}

ll solve_big(int a,int b){
    if(a == 0 && b == 1) return dp_big[a][b] = 1LL;

    ll &ret = dp_big[a][b];
    if(~ret) return ret;

    int i;
    ret = 0LL;

    for(i=1; i<=b; i++){
        ret += solve_small(a+i-1, b-i);
    }

    return ret;
}

void print_small(int a, int b, ll need, int mask){
    if(a+b == 1){
        int i;
        for(i=1; ; i++)
            if((mask&(1<<i)) == 0){
                printf("%c\n",mp[i]);
                return;
            }
    }

    int i, j, cnt;
    ll ret, pre;
    ret = pre = 0LL;

    for(i=1; i<=a; i++){
        ret += dp_big[i-1][b+a-i];

        if(ret >= need){
            cnt = 0;
            for(j=1; ; j++){
                if((mask&(1<<j)) == 0)
                    cnt++;
                if(cnt == i)
                    break;
            }
            printf("%c",mp[j]);
            return print_big(i-1, b+a-i, need-pre, mask|(1<<j));
        }

        pre = ret;
    }

    return;
}

void print_big(int a, int b, ll need, int mask){
    if(a+b == 1){
        int i;
        for(i=1; ; i++)
            if((mask&(1<<i)) == 0){
                printf("%c\n",mp[i]);
                return;
            }
    }

    int i, j, cnt;
    ll ret, pre;
    ret = pre = 0LL;

    for(i=1; i<=b; i++){
        ret += dp_small[a+i-1][b-i];

        if(ret >= need){
            cnt = 0;
            for(j=1; ; j++){
                if((mask&(1<<j)) == 0)
                    cnt++;
                if(cnt == a+i)
                    break;
            }
            printf("%c",mp[j]);
            return print_small(a+i-1, b-i, need-pre, mask|(1<<j));
        }

        pre = ret;
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    mem(dp_big, -1);
    mem(dp_small, -1);

    int test=0, t, i, j, k, n, m;
    ll num;

    scanf("%d",&t);

    while(t--){
        scanf("%s %lld",arr,&num);

        n = strlen(arr);
        sort(arr, arr+n);

        for(i=0; i<n; i++)
            mp[i+1] = arr[i];

        printf("Case %d: ",++test);

        solve_small(n, 0);
        print_small(n, 0, num, 0);
    }


    return 0;
}












