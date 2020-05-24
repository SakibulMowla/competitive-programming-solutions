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

int x[] = {-2,-2,-1,-1,1,1,2,2};//4-way
int y[] = {-1,1,-2,2,-2,2,-1,1};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  110

bool vis[30][30];
bool flag;
int r, c;

void dfs(int p, int q, int cnt)
{
    vis[p][q] = 1;
    if(flag) return;

    if(cnt == 1)
    {
        flag = 1;
        return;
    }

    int i, j, k;
    for(i=0; i<8; i++)
    {
        j = p + x[i];
        k = q + y[i];
        if(j<1 || k<1 || j>r || k>c || vis[j][k] == 1) continue;
        dfs(j, k, cnt-1);
    }

    vis[p][q] = 0;

    return;
}

int row[30], col[30];

void print(int p, int q, int cnt)
{
    vis[p][q] = 1;

    if(flag) return;
    if(cnt == 1)
    {
        int i;
        for(i=r*c; i>1; i--)
            printf("%c%d",row[i]+'A'-1,col[i]);
        printf("%c%d\n",p+'A'-1,q);
        flag = 1;
        return;
    }

    int i, j, k;
    for(i=0; i<8; i++)
    {
        j = p + x[i];
        k = q + y[i];
        if(j<1 || k<1 || j>r || k>c || vis[j][k] == 1) continue;
        row[cnt] = p, col[cnt] = q;
        print(j, k, cnt-1);
    }

    vis[p][q] = 0;

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test=0, t, i, j, k, n, m;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %d",&c,&r);

        flag = 0;
        mem(vis, 0);
        dfs(1, 1, r*c);

        printf("Scenario #%d:\n",++test);
        if(!flag) printf("impossible\n");
        else
        {
            flag = 0;
            mem(vis, 0);
            print(1, 1, r*c);
        }

        printf("\n");
    }


    return 0;
}



//A1B3C1A2B4C2A3B1C3A4B2C4
//A1B3C1A2B4C2A3B1C3A4B2C4







