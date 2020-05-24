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
#include <bitset>


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

#define SZ  110

struct data {
    int val, rep, frm, too;
    int frm1, too1, mrk;
};

string str;
data dp[SZ][SZ];
bool col[SZ][SZ];
int N;

data solve(int be, int nd) { /// begin, end
    data &ret = dp[be][nd];
    if(col[be][nd]) return ret;

    data tmp, tmp1;

    col[be][nd] = 1;
    ret.val = 1e9;

    if(be == nd) {
        ret.val = 1;
        ret.rep = 1;
        ret.frm = be;
        ret.too = nd;
        ret.mrk = 0;
        return ret;
    }

    if(be + 1 == nd) {
        tmp = solve(be, be);
        tmp1 = solve(nd, nd);
        ret.mrk = 1;
        ret.val = tmp.val + tmp1.val;
        ret.frm = be;
        ret.too = be;
        ret.frm1 = nd;
        ret.too1 = nd;
        return ret;
    }

    int i, j, k, n, m, len, l;
    string ss, tt;

    len = nd - be + 1;
    for(i = 1; i < len; i++) {
        if(len % i == 0) {
            j = k = len / i;
            tt = ss = str.substr(be, i);
            j--;
            while(j--) {
                tt = tt + ss;
            }
            if(tt == str.substr(be, len)) {
                tmp = solve(be, be + i - 1);
                if(k >= 0 && k <= 9) l = 1;
                else if(k >= 10 && k <= 99) l = 2;
                else l = 3;
                l += 2;
                if(tmp.val + l < ret.val) {
                    ret.val = tmp.val + l;
                    ret.rep = k;
                    ret.frm = be;
                    ret.too = be + i - 1;
                    ret.mrk = 0;
                }
            }
        }
    }

    for(i = be + 1; i <= nd - 1; i++) {
        tmp = solve(be, i);
        tmp1 = solve(i+1, nd);
        //if(be == 0 && nd == N-1) {
          //  printf("%d %d %d %d %d %d\n",be,i,tmp.val,i+1,nd,tmp1.val);
        //}
        if(tmp.val + tmp1.val < ret.val) {
            ret.val = tmp.val + tmp1.val;
            ret.frm = be;
            ret.too = i;
            ret.frm1 = i + 1;
            ret.too1 = nd;
            ret.mrk = 1;
        }
    }

    return ret;
}

void path(int be, int nd) {
    //printf("be = %d nd = %d\n", be, nd);
    if(be == nd) {
        printf("%c", str[be]);
        return;
    }
    if(dp[be][nd].mrk == 0) {
        if(dp[be][nd].rep > 1) printf("%d(", dp[be][nd].rep);
        path(dp[be][nd].frm, dp[be][nd].too);
        if(dp[be][nd].rep > 1) printf(")");
        return;
    }
    else {
        path(dp[be][nd].frm, dp[be][nd].too);
        path(dp[be][nd].frm1, dp[be][nd].too1);
        return;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", bedin);
//        freopen("2.txt", "w", bedout);
    #endif

    while(cin >> str) {
        mem(col, 0);
        N = sz(str);
        //printf("%d\n", solve(0, sz(str)-1).val);
        solve(0, sz(str)-1);
        path(0, sz(str)-1);
        puts("");
    }

    return 0;
}
//racecar
//AAAAABBBBBAAAAABBBBB
