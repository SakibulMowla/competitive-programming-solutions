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

void RD(int &x){scanf("%d",&x);}
void RD(ll &x){scanf("%I64d",&x);}
void RD(double &x){scanf("%lf",&x);}
void RD(int &x,int &y){scanf("%d%d",&x,&y);}
void RD(ll &x,ll &y){scanf("%I64d%I64d",&x,&y);}
void RD(double &x,double &y){scanf("%lf%lf",&x,&y);}
void RD(char *s){scanf("%s",s);}
void RD(char &s){scanf("%c",&s);}
void RD(string &s){cin>>s;}

void PR(int x) {printf("%d\n",x);}
void PR(int x,int y) {printf("%d %d\n",x,y);}
void PR(ll x) {printf("%I64d\n",x);}
void PR(char x) {printf("%c\n",x);}
void PR(char *x) {printf("%s\n",x);}
void PR(string x) {cout<<x<<endl;}

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
const ll inf = 1;
const ll mod = 1LL;

#define SZ 1010

int arr[SZ][SZ];
int dp[4][SZ][SZ];/// 0 up, 1 down, 2 left, 3 right
int row, col;

void update(int x, int y){
    int i;
    for(i=1; i<=row; i++) if(arr[i][y]) dp[0][i][y] = 1 + dp[0][i-1][y]; else dp[0][i][y] = 0;
    for(i=row; i>=1; i--) if(arr[i][y]) dp[1][i][y] = 1 + dp[1][i+1][y]; else dp[1][i][y] = 0;
    for(i=1; i<=col; i++) if(arr[x][i]) dp[2][x][i] = 1 + dp[2][x][i-1]; else dp[2][x][i] = 0;
    for(i=col; i>=1; i--) if(arr[x][i]) dp[3][x][i] = 1 + dp[3][x][i+1]; else dp[3][x][i] = 0;
}

stack <int> ms;
int pile[SZ];

int solve(int n, int indx, int hudai){
    int i, tmp, l, r, lmin, rmin, ans;

    ans = pile[indx];
    l = r = indx;
    lmin = rmin = pile[indx];

    while(r!=n || l!=1){
        if(l==1){
            rmin = min(rmin, pile[r+1]);
            r++;
        }
        else if(r==n){
            lmin = min(lmin, pile[l-1]);
            l--;
        }
        else if(pile[r+1] >= pile[l-1]){
            rmin = min(rmin, pile[r+1]);
            r++;
        }
        else {
            lmin = min(lmin, pile[l-1]);
            l--;
        }
        ans = max(ans, (r-indx+1+indx-l)*min(lmin, rmin));
    }

    return ans;
}

int solve(int x, int y){
    if(!arr[x][y]) return 0;

    int i, j, l, r, indx, ans=0;

    ///up
    {
        r = y;
        while(r+1<=col && dp[0][x][r+1]) r++;
        l = y;
        while(l-1>=1 && dp[0][x][l-1]) l--;

        j = 0;
        for(i=l; i<=r; i++){
            pile[++j] = dp[0][x][i];
            if(i == y)
                indx = j;
        }
        ans = solve(j, indx, -1);
    }

    ///down
    {
        r = y;
        while(r+1<=col && dp[1][x][r+1]) r++;
        l = y;
        while(l-1>=1 && dp[1][x][l-1]) l--;

        j = 0;
        for(i=l; i<=r; i++) {
            pile[++j] = dp[1][x][i];
            if(i == y) indx = j;
        }
        ans = max(ans, solve(j, indx, -1));
    }

    ///left
    {
        r = x;
        while(r+1<=row && dp[2][r+1][y]) r++;
        l = x;
        while(l-1>=1 && dp[2][l-1][y]) l--;

        j = 0;
        for(i=l; i<=r; i++) {
            pile[++j] = dp[2][i][y];
            if(i == x)
                indx = j;
        }
        ans = max(ans, solve(j, indx, -1));
    }

    ///right
    {
        r = x;
        while(r+1<=row && dp[3][r+1][y]) r++;
        l = x;
        while(l-1>=1 && dp[3][l-1][y]) l--;

        j = 0;
        for(i=l; i<=r; i++) {
            pile[++j] = dp[3][i][y];
            if(i == x)
                indx = j;
        }
        ans = max(ans, solve(j, indx, -1));
    }


    return ans;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    int i, j, k, q;

    while(scanf("%d %d %d",&row,&col,&q) == 3){
        mem(dp, 0);

        REP1(i, 1, row) REP1(j, 1, col) {
            RD(arr[i][j]);
        }

        REP1(i, 1, row) REP1(j, 1, col) if(arr[i][j]) dp[0][i][j] = 1 + dp[0][i-1][j];
        REP2(i, row, 1) REP1(j, 1, col) if(arr[i][j]) dp[1][i][j] = 1 + dp[1][i+1][j];
        REP1(i, 1, row) REP1(j, 1, col) if(arr[i][j]) dp[2][i][j] = 1 + dp[2][i][j-1];
        REP1(i, 1, row) REP2(j, col, 1) if(arr[i][j]) dp[3][i][j] = 1 + dp[3][i][j+1];

        while(q--){
            scanf("%d %d %d",&k,&i,&j);
            if(k == 1){
                arr[i][j] ^= 1;
                update(i, j);
            }
            else{
                PR(solve(i, j));
            }
        }

        #if defined JESI
            puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        #endif
    }

    return 0;
}


/*
5 5 3
1 1 0 0 1
0 0 0 0 0
1 1 1 1 1
1 1 0 1 0
1 0 0 1 0
1 2 2
1 1 3
2 1 3
*/


