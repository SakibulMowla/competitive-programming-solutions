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
const int inf = 1;
const ll mod = 1LL;

#define SZ  35
#define SZ1 32768+10

struct Fraction {
    ll p, q;
    Fraction (ll p, ll q): p(p), q(q) {}
    bool operator < (const Fraction &f) const {
        return p * f.q < q * f.p;
    }
};

ll K[SZ], W[SZ];
vector <ll> pre[2][92];

Fraction solve (ll num, int MW) {
    Fraction ans(1, 0);
    for(int tot = 0; tot <= MW; tot++) {
        for (int i = 0; i <= tot; i++) if(sz(pre[0][i]) && sz(pre[1][tot-i])){
            for (int j = 0; j < sz(pre[0][i]); j++) {
                ll need = num * (ll)tot - pre[0][i][j];
                vector <ll> ::iterator it = lower_bound(pre[1][tot-i].begin(), pre[1][tot-i].end(), need);

                if(it != pre[1][tot-i].end()) {
                    ll val = pre[1][tot-i][it-pre[1][tot-i].begin()] - need;
                    if(val < 0) val = -val;
                    ans = min(ans, Fraction(val, tot));
                }

                if(it != pre[1][tot-i].begin()) {
                    ll val = pre[1][tot-i][it-pre[1][tot-i].begin()-1] - need;
                    if(val < 0) val = -val;
                    ans = min(ans, Fraction(val, tot));
                }

                if(it != pre[1][tot-i].end() && it+1 != pre[1][tot-i].end()) {
                    ll val = pre[1][tot-i][it-pre[1][tot-i].begin()+1] - need;
                    if(val < 0) val = -val;
                    ans = min(ans, Fraction(val, tot));
                }
            }
        }
    }
    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n;
    ll H, S;

    while(scanf("%d %lld %lld", &n, &H, &S) == 3) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &K[i], &W[i]);
            cnt += (int)W[i];
        }

        int n1 = n / 2, n2 = n - n1;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j <= cnt; j++)
                clr(pre[i][j]);

        int lim = (1<<n1);
        for (int mask = 0; mask < lim; mask++) {
            ll k = 0, w = 0;
            for (int i = 0; i < n1; i++) if(mask & (1<<i)) {
                k += K[i] * W[i];
                w += W[i];
            }
            pre[0][w].pb(k);
        }

        lim = (1<<n2);
        for (int mask = 0; mask < lim; mask++) {
            ll k = 0, w = 0;
            for (int i = 0; i < n2; i++) if(mask & (1<<i)) {
                k += K[i+n1] * W[i+n1];
                w += W[i+n1];
            }
            pre[1][w].pb(k);
        }

        for (int i = 0; i <= cnt; i++) {
            sort(pre[1][i].begin(), pre[1][i].end());
        }

        Fraction ansH = solve(H, cnt);
        Fraction ansS = solve(S, cnt);


        if(ansH < ansS) printf("Hawks\n");
        else if(ansS < ansH) printf("Swans\n");
        else printf("Tie\n");
    }

    return 0;
}










