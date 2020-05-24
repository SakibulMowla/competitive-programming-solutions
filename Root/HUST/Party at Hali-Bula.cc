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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define SZ 210

int dp[SZ][3];
vector <int> adj[SZ];
map <string , int> mp;
int N;

int solve(int u, int col){
    int &ret = dp[u][col];
    if(ret != -1) return ret;

    int i, k;
    ret = col;
    k = sz(adj[u]);

    REP(i, k){
        if(col == 0) ret += max(solve(adj[u][i], 0), solve(adj[u][i], 1));
        else ret += solve(adj[u][i], 0);
    }

    return ret;
}

bool flag;

void path(int u, int col){
    if(flag) return;

    int i, k, tmp, tmp1;
    k = sz(adj[u]);

    REP(i, k){
        if(col == 0){
            if(dp[ adj[u][i] ][0] == dp[ adj[u][i] ][1]){
                flag = true;
                return;
            }
            else if(dp[ adj[u][i] ][0] > dp[ adj[u][i] ][1]) path(adj[u][i], 0);
            else path(adj[u][i], 1);
        }
        else path(adj[u][i], 0);
    }

    return;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, i, j, k;
    char s1[110], s2[110];

    while(scanf("%d",&n) == 1 && n){
        clr(mp);
        for(i=0;i<=n+1;i++) clr(adj[i]), dp[i][0] = dp[i][1] = -1;
        k = 0;
        N = n;

        scanf("%s",s1);
        mp[s1] = ++k;

        REP(i, n-1){
            scanf("%s %s",s1,s2);
            if(mp.find(s1) == mp.end()) mp[s1] = ++k;
            if(mp.find(s2) == mp.end()) mp[s2] = ++k;
            adj[ mp[s2] ].pb(mp[s1]);
        }

        printf("%d ",max(solve(1, 0), solve(1, 1)));

        flag = false;
        if(dp[1][0] == dp[1][1]) flag = true;
        else if(dp[1][0] > dp[1][1]) path(1, 0);
        else path(1, 1);

        flag ? puts("No") : puts("Yes");
     }



    return 0;
}


/*
7
a
b a
c a
d a
e c
f c
g c

Ans = 5 Yes
*/













