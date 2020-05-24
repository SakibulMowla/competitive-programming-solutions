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
const int inf = 1E9;
const ll mod = 1LL;

#define SZ  310

int cost[2][32][22];
int sample[32];

int dp[SZ][SZ];
int col[SZ][SZ];
int cur;
int path[32];

int solve(int T1, int T2, int pos)
{
    int &ret = dp[T1][T2];

    if(col[T1][T2] == cur) return ret;
    if(!pos) return ret = 0;

    col[T1][T2] = cur;
    ret = inf;

    for(int i = 0; i <= sample[pos]; i++)
    {
        if(T1-i < 0 || T2-(sample[pos]-i) < 0) continue;

        int tmp = solve(T1-i, T2-(sample[pos]-i), pos-1) + cost[0][pos][i] + cost[1][pos][sample[pos]-i];
        if(tmp < ret)
        {
            ret = tmp;
        }
    }

    return ret;
}

void clean_up(int T1, int T2, int pos)
{
    if(pos == 0) return;
    int &ret = dp[T1][T2];

    for(int i = 0; i <= sample[pos]; i++)
    {
        if(T1-i < 0 || T2-(sample[pos]-i) < 0) continue;

        int tmp = dp[T1-i][T2-(sample[pos]-i)] + cost[0][pos][i] + cost[1][pos][sample[pos]-i];
        if(tmp == ret)
        {
            path[pos] = i;
            return clean_up(T1-i, T2-(sample[pos]-i), pos-1);
        }
    }
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m;

    while(scanf("%d %d", &n, &m) == 2 && (n + m))
    {
        int sites;
        scanf("%d", &sites);

        for(int i = 1; i <= sites; i++)
        {
            scanf("%d", &sample[i]);

            for(int j = 1; j <= sample[i]; j++)
                scanf("%d", &cost[0][i][j]);

            for(int j = 1; j <= sample[i]; j++)
                scanf("%d", &cost[1][i][j]);
        }

        cur++;
        printf("%d\n", solve(n, m, sites));
        clean_up(n, m, sites);

        for(int i = 0; i < sites; i++)
        {
            if(i) printf(" ");
            printf("%d",path[i+1]);
        }

        puts("");
        puts("");
    }

    return 0;
}













