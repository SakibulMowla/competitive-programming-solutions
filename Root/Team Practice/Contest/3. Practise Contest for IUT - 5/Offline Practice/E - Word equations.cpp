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

#define SZ  2010

int lft[SZ], rht[SZ];
string cntr[SZ];

int has[SZ][26];
bool visited[SZ];

void dfs_prepare(int node) {
    visited[node] = 1;

    if(!lft[node]) {
        int i, k;
        k = sz(cntr[node]);
        for(i = 0; i < k; i++) {
            has[node][ cntr[node][i]-'a' ] = 1;
        }
        return;
    }

    if(!visited[ lft[node] ]) dfs_prepare(lft[node]);
    if(!visited[ rht[node] ]) dfs_prepare(rht[node]);

    int i;
    for(i = 0; i < 26; i++)
        has[node][i] = has[ lft[node] ][i] | has[ rht[node] ][i];

    return;
}

string txt;
int pos, N;

void dfs_solve(int node) {
    if(pos == N)
        return;

    if(!lft[node]) {
        int i, k = sz(cntr[node]);
        for(i = 0; i < k && pos < N; i++) {
            if(txt[pos] == cntr[node][i])
                pos++;
        }
        return;
    }

    if(pos < N && has[ lft[node] ][ txt[pos]-'a' ])dfs_solve(lft[node]);
    if(pos < N && has[ rht[node] ][ txt[pos]-'a' ])dfs_solve(rht[node]);

    return;
}

char a[10], b[10], c[10], str[30];
map <string , int> mp;

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int t, q, i, m, cnt;

    scanf("%d",&t);
    while(t--) {
        scanf("%d",&q);

        mp.clear();
        cnt = 0;
        memset(has, 0, sizeof(has));
        memset(lft, 0, sizeof(lft));
        memset(lft, 0, sizeof(rht));
        memset(visited, 0, sizeof(visited));

        while(q--) {
            scanf(" %[^\n]",str);
            m = sscanf(str, "%s = %s + %s", a, b, c);

            if(m == 3) {
                if(mp.find(a) == mp.end()) mp[a] = ++cnt;
                if(mp.find(b) == mp.end()) mp[b] = ++cnt;
                if(mp.find(c) == mp.end()) mp[c] = ++cnt;

                lft[ mp[a] ] = mp[b];
                rht[ mp[a] ] = mp[c];
            }
            else {
                if(mp.find(a) == mp.end()) mp[a] = ++cnt;
                cntr[ mp[a] ] = b;
            }
        }

        scanf("%s",a);
        cin >> txt;

        N = sz(txt);
        pos = 0;

        dfs_prepare(mp[a]);
        dfs_solve(mp[a]);

        printf("%s\n",pos==N ? "YES" : "NO");
    }


    return 0;
}











