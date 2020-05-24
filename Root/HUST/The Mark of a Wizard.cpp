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

#define SZ 110

struct data
{
    int to, val;
    data(){}
    data(int a, int b)
    {
        to = a;
        val = b;
    }
};

vector <data> v[SZ];

pii dp[SZ];

int strt, end;

pii solve(int u)
{
    pii &ret = dp[u];
    if(u == end)
    {
        return ret = MP(0, 0);
    }

    if(ret.X != -1) return ret;

    vector <pii> tmp;
    pii haha;

    int i, j, k, l;
    k = sz(v[u]);

    ret.X = 1e9;
    ret.Y = 1e9;

    REP(i, k)
    {
        j = v[u][i].to;
        l = v[u][i].val;
        haha = solve(j);
        haha.X += l;
        ret.X = min(ret.X, haha.X);
        tmp.pb(haha);
    }

    sort(tmp.begin(), tmp.end());

    k = sz(tmp);

    if(k && tmp[0].X == tmp[k-1].X)
    {
        ret.Y = -1e9;
        REP(i, k)
        {
            ret.Y = max(ret.Y, tmp[i].Y);
        }
        REP(i, k)
        {
            ret.Y = min(ret.Y, 1+tmp[i].Y);
        }
    }
    else
    {
        REP(i, k)
        {
            if(tmp[i].X == ret.X && tmp[i].Y+1 < ret.Y)
            {
                ret.Y = tmp[i].Y + 1;
            }
        }
    }

    return ret;
}

map <char, int> mp;
char s[110];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, n, m, cnt, l;
    char ch, ch1;

    while(scanf("%d",&n) == 1 && n)
    {
        REP(i, 100) clr(v[i]);
        clr(mp);
        cnt = 0;

        REP(i, n)
        {
            scanf(" %s %d",s,&j);
            ch = s[0];
            assert(strlen(s) == 1);

            if(mp.find(ch) == mp.end())
            {
                mp[ch] = ++cnt;
                k = mp[ch];
            }
            else k = mp[ch];
            if(ch == 'A') strt = k;
            if(i == n-1) end = k;

            while(j--)
            {
                scanf(" %s %d",&s,&m);
                ch1 = s[0];
                assert(strlen(s) == 1);
                if(mp.find(ch1) == mp.end())
                {
                    mp[ch1] = ++cnt;
                    l = mp[ch1];
                }
                else l = mp[ch1];

                v[k].pb(data(l, m));
            }
        }

        for(i=0; i<=cnt; i++)
            dp[i].X = -1;

        printf("%d %d\n",solve(strt));
    }

    return 0;
}


/*
17
A 3 B 2 L 1 K 3
B 3 C 2 O 5 M 2
C 2 D 4 O 3
D 2 E 2 P 1
E 1 F 2
F 1 Q 4
G 1 Q 3
H 1 G 1
I 2 P 1 H 2
J 3 N 1 P 4 I 3
K 2 O 4 J 2
L 2 M 3 K 2
M 3 O 3 N 2 J 1
N 2 P 3 I 2
O 2 E 3 P 2
P 3 F 3 G 4 H 1
Q 0
*/

