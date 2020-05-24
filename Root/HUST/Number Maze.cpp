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

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

int x[] = {0,0,-1,1};//4-way
int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1e6;
const ll mod = 1LL;

#define SZ 1010

int grid[SZ][SZ];
int dp[SZ][SZ];

struct data{
    int i, j, c;
    data(){}
    data(int x, int y,int z){
        i = x, j = y, c = z;
    }
    bool operator < (const data &x) const{
        return c > x.c;
    }
};

priority_queue <data> pq;

int r, c;

int dijkrtra(){
    while(!pq.empty()) pq.pop();
    int i, j, a, b, d, u, v;
    data dd;

    REP1(i, 1, r) REP1(j, 1, c) dp[i][j] = inf;
    dp[1][1] = grid[1][1];
    pq.push(data(1, 1, grid[1][1]));

    while(!pq.empty()){
        dd = pq.top(); pq.pop();

        a = dd.i;
        b = dd.j;
        d = dd.c;

        REP(i, 4){
            u = a + x[i];
            v = b + y[i];
            if(u>=1 && u<=r && v>=1 && v<=c && dp[u][v] > d + grid[u][v]){
                dp[u][v] = d + grid[u][v];
                pq.push(data(u, v, dp[u][v]));
            }
        }
    }

    return dp[r][c];
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int test, i, j;

    scanf("%d",&test);

    while(test--){
        scanf("%d %d",&r,&c);

        REP1(i, 1, r) REP1(j, 1, c)scanf("%d",&grid[i][j]);

        printf("%d\n",dijkrtra());
    }


    return 0;
}













