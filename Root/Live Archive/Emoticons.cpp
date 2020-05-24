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

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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
const int inf = 1e9;
const ll mod = 1LL;

#define SZ  110

void pre_process(char pat[], int par[])
{
    int len = strlen(pat), k = 0;
    par[0] = 0;
    for(int i = 1; i < len; i++)
    {
        while(k > 0 && pat[i] != pat[k])
            k = par[k-1];
        if(pat[i] == pat[k])
            k++;
        par[i] = k;
    }
}

int track[110];

void kmp(char txt[], char pat[], int par[])
{
    int tlen = strlen(txt), plen = strlen(pat);
    int k = 0;

    for(int i = 0; i < tlen; i++)
    {
        while(k > 0 && txt[i] != pat[k])
            k = par[k-1];
        if(txt[i] == pat[k])
            k++;
        if(k == plen)
        {
            k = par[k-1];
            track[i] = min(track[i], plen);
        }
    }
}

int N, pat_cnt;

int solve()
{
    int ret = 0;
    int pre = -1;
    for(int i = 0; i < N; i++)
        if(track[i] != inf)
        {
            if(i - track[i] + 1 <= pre) continue;
            ret++;
            pre = i;
        }
    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    char pat[110][20];
    char txt[110];
    int par[110][20];

    int n, m;

    while(scanf("%d %d", &n, &m) == 2 && (n + m))
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%s", pat[i]);
            pre_process(pat[i], par[i]);
        }
        getchar();

        int ans = 0;
        for(int i = 0; i < m; i++)
        {
            gets(txt);

            for(int j = 0; j < 100; j++)
                track[j] = inf;

            for(int j = 0; j < n; j++)
                kmp(txt, pat[j], par[j]);

            N = strlen(txt);
            ans += solve();
        }
        printf("%d\n", ans);
    }


    return 0;
}













