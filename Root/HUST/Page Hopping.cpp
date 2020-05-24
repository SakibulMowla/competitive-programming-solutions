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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ 110

map <int , int> mp;
int dist[SZ][SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int a, b, i, j, l, k, test=0;
    double d;

    while(scanf("%d %d",&a,&b) == 2 && (a||b)){
        clr(mp);
        REP1(i, 1, 100){
            REP1(j, 1, 100) dist[i][j] = dist[j][i] = inf;
            dist[i][i] = 0;
        }

        k = 0;

        if(mp.find(a) == mp.end()) mp[a] = ++k;
        if(mp.find(b) == mp.end()) mp[b] = ++k;
        dist[ mp[a] ][ mp[b] ] = 1;

        while(scanf("%d %d",&a,&b) && (a||b)){
            if(mp.find(a) == mp.end()) mp[a] = ++k;
            if(mp.find(b) == mp.end()) mp[b] = ++k;
            dist[ mp[a] ][ mp[b] ] = 1;
        }

        REP1(l, 1, k) REP1(i, 1, k) REP1(j, 1, k)
            dist[i][j] = min(dist[i][j], dist[i][l]+dist[l][j]);

        a = 0;
        REP1(i, 1, k){
            REP1(j, 1, k){
                if(i == j) continue;
                a += dist[i][j];
            }
        }

        b = k * (k-1);
        d = (double)a/(double)b;


        printf("Case %d: average length between pages = %.3lf clicks\n",++test,d);
    }



    return 0;
}
















