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

int x[SZ], y[SZ];
int xsz, ysz;

struct arr {
    int x, y;
};

arr data[SZ];
int cum[SZ][SZ];
int cnt[SZ];

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, test = 0;

    while(scanf("%d", &n) == 1 && n) {
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &data[i].x, &data[i].y);
            x[i] = data[i].x;
            y[i] = data[i].y;
        }

        sort(x, x+n);
        sort(y, y+n);
        xsz = unique(x, x+n)-x;
        ysz = unique(y, y+n)-y;

//        for (int i = 0; i < xsz; i++) printf(" %d", x[i]);
//        puts("");
//        for (int i = 0; i < ysz; i++) printf(" %d", y[i]);
//        puts("");

        if(xsz <= 2 || ysz <= 2) {
            printf("Case %d: %d\n", ++test, n);
            continue;
        }

        mem(cum, 0);
        mem(cnt, 0);
        for (int i = 0; i < n; i++) {
            data[i].x = lower_bound(x, x+xsz, data[i].x)-x;
            data[i].y = lower_bound(y, y+ysz, data[i].y)-y;
            cum[ data[i].y ][ data[i].x ]++;
            cnt[ data[i].x ]++;
//            if(data[i].y == 2) {
//                printf("___________________ %d\n", data[i].x);
//            }
        }

        for (int col = 0; col < ysz; col++)
            for (int row = 1; row < xsz; row++)
                cum[col][row] += cum[col][row-1];
//
//        printf("cum[2][0] = %d\n", cum[2][0]);
//        printf("cum[2][1] = %d\n", cum[2][1]);
//        printf("cum[2][2] = %d\n", cum[2][2]);
//        printf("cum[2][3] = %d\n", cum[2][3]);
//        printf("cum[2][4] = %d\n", cum[2][4]);
//        printf("cum[2][5] = %d\n", cum[2][5]);
//        printf("cum[2][6] = %d\n", cum[2][6]);
//        printf("cum[2][7] = %d\n", cum[2][7]);

        int ans = 0;
        for (int i = 0; i < xsz; i++) {
//            printf("--------------- x  = %d\n",x[i]);
            for (int j = i+1; j < xsz; j++) {
                int best1 = 0, best2 = 0;
                for (int k = 0; k < ysz; k++) {
                    int tmp = 0;
                    if (i <= j-1) tmp = cum[k][j-1] - cum[k][i];
                    if (tmp > best1) {
                        best2 = best1;
                        best1 = tmp;
                    } else if (tmp > best2) {
                        best2 = tmp;
                    }
                }
                if (best1+best2+cnt[i]+cnt[j] > ans) {
                    ans = best1+best2+cnt[i]+cnt[j];
//                    printf(">>> i = %d j = %d %d %d ans = %d\n", i, j, x[i], x[j], ans);
                }
                if (x[i] == 1 && x[j] == 11) {
//                    printf(">>> i = %d j = %d %d %d ans = %d\n", i, j, x[i], x[j], ans);
//                    printf(">>>> %d %d\n", cnt[i] ,cnt[j]);
                }
            }
        }

        printf("Case %d: %d\n", ++test, ans);
    }


    return 0;
}










