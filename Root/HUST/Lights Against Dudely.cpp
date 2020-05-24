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

char arr[SZ][SZ];
int row, col;

set <pii> ms, tmp;

void doit(int x, int y, int c = 1){
    pii p;

    if(c == 1){
        p = MP(x-1, y);
        if(x-1>=1 && ms.find(p) == ms.end()) return;
        p = MP(x, y+1);
        if(y+1<=col && ms.find(p) == ms.end()) return;
    }
    else if(c == 2){
        p = MP(x, y+1);
        if(y+1<=col && ms.find(p) == ms.end()) return;
        p = MP(x+1, y);
        if(x+1<=row && ms.find(p) == ms.end()) return;
    }
    else if(c == 3){
        p = MP(x+1, y);
        if(x+1<=row && ms.find(p) == ms.end()) return;
        p = MP(x, y-1);
        if(y-1>=1 && ms.find(p) == ms.end()) return;
    }
    else {
        p = MP(x, y-1);
        if(y-1>=1 && ms.find(p) == ms.end()) return;
        p = MP(x-1, y);
        if(x-1>=1 && ms.find(p) == ms.end()) return;
    }
//    set <pii> it;

    p = MP(x, y);
    if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));

    if(c == 1){
        p = MP(x-1, y);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));

        p = MP(x, y+1);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));
    }
    else if(c == 2){
        p = MP(x, y+1);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));

        p = MP(x+1, y);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));
    }
    else if(c == 3){
        p = MP(x+1, y);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));

        p = MP(x, y-1);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));
    }
    else {
        p = MP(x, y-1);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));

        p = MP(x-1, y);
        if(tmp.find(p) != tmp.end()) tmp.erase(tmp.find(p));
    }
}

vector <pii> v;

bool solve(int mask, int cnt){
    int i, j, k;

    for(i=0; i<cnt; i++) if(mask & (1<<i)) {
        for(k=1; k<=4; k++){
            tmp = ms;
            doit(v[i].X, v[i].Y, k);
            for(j=0; j<cnt; j++) if(mask & (1<<j)) {
                if(j == i) continue;
                doit(v[j].X, v[j].Y);
            }
            if(sz(tmp) == 0) return true;
        }
    }

    return false;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, cnt, lim, mask, ans;

    while(scanf("%d %d",&row,&col) == 2 && (row || col)){
        clr(ms);
        clr(v);
        cnt = 0;
        ans = 1e9;

        REP1(i, 1, row) scanf("%s",arr[i]+1);
        REP1(i, 1, row) REP1(j, 1, col) if(arr[i][j] == '.'){
            ms.insert(MP(i, j));
            v.pb(MP(i, j));
            cnt++;
        }

        lim = (1<<cnt) - 1;
        REP1(mask, 0, lim){
            j = __builtin_popcount(mask);
            if(j < ans && solve(mask, cnt))
                ans = j;
        }

        if(cnt == 0) ans = 0;
        if(ans == 1e9) printf("-1\n");
        else printf("%d\n",ans);
    }


    return 0;
}
















