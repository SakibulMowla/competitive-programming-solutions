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

#define SZ  1010
#define SZ1 1000010

char grid[SZ][SZ];
int par[SZ1], rank[SZ1];

void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        rank[i] = 0;
    }
    return;
}

int find(int r)
{
    if(r == par[r]) return r;
    return par[r] = find(par[r]);
}

void Union(int x, int y) {
//    printf("%d %d\n", x, y);
    x = find(x);
    y = find(y);
//    printf("%d %d\n", x, y);
    if (x != y) {
        if (rank[x] > rank[y]) {
            par[y] = x;
        } else {
            par[x] = y;
            rank[y] = max(rank[y], rank[x]+1);
        }
    }
    return;
}

int x[SZ], y[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int n, m, k;
    while(scanf("%d %d %d", &n, &m, &k) == 3) {
        init(n*m+2);
        for (int i = 0; i < m; i++) {
            x[i] = n;
            y[i] = -1;
        }

        for (int i = 0; i < n; i++)
            scanf("%s", grid[i]);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j] == '.') {
                    if(i+1 < n && grid[i+1][j] == '.') {
                        Union(i * m + j, (i+1) * m + j);
                    }
                    if(j+1 < m && grid[i][j+1] == '.') {
                        Union(i * m + j, i * m + j + 1);
                    }
                    if(i == 0) {
                        Union(i * m + j, n * m);
                    }
                    if(i == n-1) {
                        Union(i * m + j, n * m + 1);
                    }
                } else {
                    x[j] = min(x[j], i);
                    y[j] = max(y[j], i);
                }
            }
        }

        int ans = 100001;
        if(find(n * m) == find(n * m + 1)) ans = 0;

        for (int i = 0; i < k; i++) {
            int atk;
            scanf("%d", &atk);
//            inp(atk);
            if(ans != 100001) continue;

            int dir = atk / abs(atk);
            atk = abs(atk);
            atk--;

            if (dir == 1 && x[atk] != n) {
                int p = x[atk], q = atk;
                grid[p][ q ] = '.';

                if(p+1 < n && grid[ p+1 ][q] == '.') {
                    Union(p * m + q, (p+1) * m + q);
                }
                if(p-1 >= 0 && grid[ p-1 ][q] == '.') {
                    Union(p * m + q, (p-1) * m + q);
                }
                if(q+1 < m && grid[ p ][q+1] == '.') {
                    Union(p * m + q, p * m + q + 1);
                }
                if(q-1 >= 0 && grid[ p ][q-1] == '.') {
                    Union(p * m + q, p * m + q - 1);
                }
                if(p == 0) {
                    Union(n * m, 0 * m + q);
                }
                if(p == n - 1) {
                    Union(n * m + 1, (n - 1) * m + q);
                }
                while(x[q] < n && grid[x[q]][ q ] == '.') {
                    x[q]++;
                }
            } else if (dir == -1 && y[atk] != -1) {
                int p = y[atk], q = atk;
                grid[ p ][ q ] = '.';

                if(p+1 < n && grid[ p+1 ][q] == '.') {
                    Union(p * m + q, (p+1) * m + q);
                }
                if(p-1 >= 0 && grid[ p-1 ][q] == '.') {
                    Union(p * m + q, (p-1) * m + q);
                }
                if(q+1 < m && grid[ p ][q+1] == '.') {
                    Union(p * m + q, p * m + q + 1);
                }
                if(q-1 >= 0 && grid[ p ][q-1] == '.') {
                    Union(p * m + q, p * m + q - 1);
                }
                if(p == n - 1) {
                    Union(n * m + 1, (n - 1) * m + q);
                }
                if(p == 0) {
                    Union(n * m, 0 * m + q);
                }
                while(y[q] >= 0 && grid[ y[q] ][ q ] == '.') {
                    y[q]--;
                }
            }

            if(find(n * m) == find(n * m + 1))
                ans = dir * (i+1);
        }

        if(ans == 100001) printf("X\n");
        else printf("%d\n", ans);
    }

    return 0;
}












