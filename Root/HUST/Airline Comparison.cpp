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

#define SZ 310

map <char , int> mp;
int dist1[SZ][SZ], dist2[SZ][SZ];

void init(){
    clr(mp);
    int i, j;
    REP1(i, 1, SZ-1) {
        REP1(j, 1, SZ-1) dist1[i][j] = dist1[j][i] = dist2[i][j] = dist2[j][i] = inf;
        dist1[i][i] = dist2[i][i] = 0;
    }
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test, i, j, k, n, m, node;
    char c1, c2;
    bool f;

    scanf("%d",&test);

    while(test--){
        init();
        node = 0;

        scanf("%d",&n);
        REP(i, n){
            scanf(" %c %c",&c1,&c2);
            c1 = tolower(c1);
            c2 = tolower(c2);
            if(mp.find(c1) == mp.end()) mp[c1] = ++node;
            if(mp.find(c2) == mp.end()) mp[c2] = ++node;
            dist1[ mp[c1] ][ mp[c2] ] = dist1[ mp[c2] ][ mp[c1] ] = 1;
        }

        REP1(k, 1, node) REP1(i, 1, node) REP1(j, 1, node)
            dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);

        scanf("%d",&m);
        REP(i, m){
            scanf(" %c %c",&c1,&c2);
            c1 = tolower(c1);
            c2 = tolower(c2);
            if(mp.find(c1) == mp.end()) mp[c1] = ++node;
            if(mp.find(c2) == mp.end()) mp[c2] = ++node;
            dist2[ mp[c1] ][ mp[c2] ] = dist2[ mp[c2] ][ mp[c1] ] = 1;
        }

        REP1(k, 1, node) REP1(i, 1, node) REP1(j, 1, node)
            dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);

        f = true;
        REP1(i, 1, node){
            REP1(j, i+1, node){
                if( (dist1[i][j] == inf && dist2[i][j] < inf) || (dist2[i][j] == inf && dist1[i][j] < inf) ){
                    f = false;
                    goto HERE;
                }
            }
        }

        HERE:;
        f ? puts("YES") : puts("NO");
        if(test) puts("");
    }


    return 0;
}
















