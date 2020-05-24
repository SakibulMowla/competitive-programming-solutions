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

#define SZ  1010

int dp1[SZ][SZ], dp2[SZ][SZ];
vector <int> adj[SZ];

int solve1(int pre, int now){
    int &ret = dp1[pre][now];
    if(~ret) return ret;

    int i, j, k;
    ret = 1;

    k = sz(adj[now]);
    REP(i, k){
        j = adj[now][i];
        if(j == pre) continue;
        ret += solve1(now, j);
    }

    return ret;
}

int solve2(int pre, int now){
//    printf("now %d %d\n",now,pre);
    int &ret = dp2[pre][now];
    if(~ret) return ret;

    int i, j, k, best1, best2, indx1, indx2;
    j = k = sz(adj[now]);
    ret = 0;

    if(now != pre) j--;
    if(!(j==0 || j==2)){
//        printf("j = %d\n",j);
        if(j == 1)
            ret = solve1(pre, now) - 1;
        else{
            best1 = best2 = 0;
            indx1 = indx2 = -1;
            REP(i, k){
                j = adj[now][i];
                if(j == pre) continue;
                j = solve1(now, j) - solve2(now, j);
                if(j >= best1){
                    if(indx1 != -1){
                        best2 = best1;
                        indx2 = indx1;
                    }
                    best1 = j;
                    indx1 = adj[now][i];
                }
                else if(j >= best2){
                    best2 = j;
                    indx2 = adj[now][i];
                }
            }
            REP(i, k){
                j = adj[now][i];
                if(j == pre || j==indx1 || j==indx2) continue;
                ret += solve1(now, j);
            }
//            printf("indx   %d %d\n",indx1,indx2);
            ret += solve2(now, indx1) + solve2(now, indx2);
        }
    }
    else{
        REP(i, k){
            j = adj[now][i];
            if(j == pre) continue;
            ret += solve2(now, j);
        }
    }

    return ret;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int test=0, t, i, j, k, n, ans;

    scanf("%d",&t);
//    printf("t = %d\n",t);

    while(t--){
        scanf("%d",&n);
//        printf("n = %d\n",n);

        mem(dp1, -1);
        mem(dp2, -1);
        ans = 1010;
        REP1(i, 0, n) clr(adj[i]);

//        printf("ok\n");

        REP(i, n-1){
            scanf("%d %d",&j,&k);
//            printf("jk %d %d\n",j,k);
            adj[j].pb(k);
            adj[k].pb(j);
        }

//        printf("ok\n");

        REP1(i, 1, n){
            ans = min(ans, solve2(i, i));
//            printf("%d %d\n",i,ans);
        }

        printf("Case #%d: %d\n",++test,ans);
    }

    return 0;
}







/*
6
1 2
1 3
1 4
4 5
4 6
ans = 1
*/






