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

#define eps 1e-9

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

int used[20];

struct data{
    int x, y;
    data(){}
    data(int a, int b){
        x = a;
        y = b;
    }
};

data point[30];
double best;

vector <int> tmp, ans;

void bctk(int lvl, double d, int p){
    if(lvl == 4){
        if(d >= best){
            best = d;
            ans = tmp;
        }
        return;
    }

    int i, j, k;
    double dist;
    for(i=0; i<=23; i++){
        if(used[i] == 0){
            used[i] = 1;
            tmp.pb(point[i].x);
            tmp.pb(point[i].y);
            if(lvl)
                dist = sqrt( (point[p].x-point[i].x)*(point[p].x-point[i].x) + (point[p].y-point[i].y)*(point[p].y-point[i].y) );
            else dist = 0;
            bctk(lvl+1, d+dist, i);
            used[i] = 0;
            tmp.pop_back();
            tmp.pop_back();
        }
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;

    while(cin >> n >> m){

        if(n == 0){
            printf("%d %d\n",0,1);
            printf("%d %d\n",n,m);
            printf("0 0\n");
            printf("%d %d\n",0,m-1);
//            assert(n==0&&m==10);
        }
        else if(m == 0){
            printf("%d %d\n",1,0);
            printf("%d %d\n",n,m);
            printf("%d %d\n",0,0);
            printf("%d %d\n",n-1,0);
//            assert(0);
        }
        else{
            best = 0;
            clr(tmp);
            mem(used, 0);

            point[0].x = 0; point[0].y = 0;
            point[1].x = n; point[1].y = m;
            point[2].x = n; point[2].y = 0;
            point[3].x = 0; point[3].y = m;
            point[4].x = 0; point[4].y = 1;
            point[5].x = 1; point[5].y = 0;
            point[6].x = n-1; point[6].y = 0;
            point[7].x = n; point[7].y = 1;
            point[8].x = n-1; point[8].y = m;
            point[9].x = n; point[9].y = m-1;
            point[10].x = 0; point[10].y = m-1;
            point[11].x = 1; point[11].y = m;
            point[12].x = 1; point[12].y = 1;
            point[13].x = n-1; point[13].y = m-1;
            point[14].x = 1; point[14].y = m-1;
            point[15].x = n-1; point[15].y = 1;
            point[16].x = n/2; point[16].y = 0;
            point[17].x = n/2+1; point[17].y = 0;
            point[18].x = n; point[18].y = m/2;
            point[19].x = n; point[19].y = m/2+1;
            point[20].x = n/2; point[20].y = m;
            point[21].x = n/2+1; point[21].y = m;
            point[22].x = 0; point[22].y = m/2;
            point[23].x = 0; point[23].y = m/2+1;

            for(int i=0; i<=23; i++)
                for(int j=i+1; j<=23; j++)
                    if(point[i].x==point[j].x && point[i].y == point[j].y)
                        used[j] = 1;

            bctk(0, 0, 0);

//            printf("%.10lf\n",best);

//            printf("0 0\n");
            for(int i=0; i<sz(ans); i+=2)
                printf("%d %d\n",ans[i],ans[i+1]);
        }

        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}


//41.0493837179
//41.0493837179


