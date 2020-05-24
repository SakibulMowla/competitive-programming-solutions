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
const ll mod = 1LL;

#define SZ 1010

double dp[2][SZ][SZ];

double solve(int player, double w, double b){
    if(w == 0 && b == 0) return 0.0;
    if(b == 0){
        if(player == 0) return 1.0;
        return 0.0;
    }

    double &ret = dp[player][(int)w][(int)b];
    if(ret != -1.0) return ret;

    ret = 0;
    int cnt = 0;

    if(player == 0){
        if(w != 0){
//            ret += 1.00;
            ret += 1.00 * (w/(w+b)*1.0);
            cnt++;
        }
        if(b != 0){
//            ret += solve(!player, w, b-1);
            ret += solve(!player, w, b-1) * (b/(w+b)*1.0);
            cnt++;
        }
    }
    else{
        if(w != 0){
            cnt++;
        }
        if(b != 0){
            if(b+w == 1){
//                ret += solve(!player, w, b-1);
                ret += solve(!player, w, b-1) * (b/(w+b)*1.0);
                cnt++;
            }
            else if(b+w == 2){
                if(b == 2){
//                    ret += solve(!player, w, b-2);
                    ret += solve(!player, w, b-2) * (b/(w+b)*1.0) * ((b-1)/(w+b-1)*1.0);
                    cnt++;
                }
                else {
//                    ret += solve(!player, w-1, b-1);
                    ret += solve(!player, w-1, b-1) * (b/(w+b)*1.0) * (w/(w+b-1)*1.0);
                    cnt++;
                }
            }
            else if(b+w >= 3 && w>=1){
//                ret += solve(!player, w-1, b-1) + solve(!player, w, b-2);
                ret += solve(!player, w-1, b-1) * (b/(w+b)*1.0) * (w/(w+b-1)*1.0) + solve(!player, w, b-2) * (b/(w+b)*1.0) * ((b-1)/(w+b-1)*1.0);
                cnt += 2;
            }
            else {
//                ret += solve(!player, w, b-2);
                ret += solve(!player, w, b-2) * (b/(w+b)*1.0) * ((b-1)/(w+b-1)*1.0);
                cnt++;
            }
        }
    }

//    ret /= (double)(cnt);

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int w, b, i, j;

    while(scanf("%d %d",&w,&b) == 2){
        REP(i, 1002) REP(j, 1002) dp[0][i][j] = dp[1][i][j] = (double)-1.0;
        printf("%.10lf\n",solve(0, w, b));
    }


    return 0;
}















