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

#define SZ  110

struct data {
    int u, v;
    ll w;
    data () {}
    data (int u, int v, ll w): u(u), v(v), w(w) {}
};

bool comp (pll p, pll q) {
    return p.Y < q.Y;
}

int main() {
//    #if defined JESI
//        freopen("flights.in", "r", stdin);
//        freopen("flights.out", "w", stdout);
//    #endif

    ios::sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m && (n+m)) {
        vector <data> a(m);
        vector <pll> sum(n, {0, 0});
        vector <int> indx(n);
        ll now = 0;

        for (int i = 0; i < n; i++) {
            sum[i].X = i;
        }

        for (int i = 0; i < m; i++) {
            cin >> a[i].u >> a[i].v;
            --a[i].u;
            --a[i].v;
            if (a[i].u != 0 && a[i].v != 0) {
                a[i].w = ++now;
                sum[ a[i].u ].Y += now;
                sum[ a[i].v ].Y += now;
            }
            if (min(a[i].u, a[i].v) == 0) {
                indx[max(a[i].u, a[i].v)] = i;
            }
        }

        sort(sum.begin(), sum.end(), comp);

        for (int i = 0; i < n; i++) {
            if (sum[i].X == 0) continue;
            a[indx[ sum[i].X ]].w = ++now;
        }

        cout << "Yes" << endl;
        for (int i = 0; i < m; i++) {
            if (i) cout << ' ';
            cout << a[i].w;
        }
        cout << endl;
    }

    return 0;
}











