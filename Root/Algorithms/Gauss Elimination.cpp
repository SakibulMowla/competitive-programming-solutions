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

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=1;(i)<=(int)(n);(i)++)
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
const ll inf = 1LL<<28;
const ll mod = 1LL;

#define eps 1e-6
#define SZ 110

double a[SZ][SZ], b[SZ], s[SZ], x[SZ];

void substitute(int n){
    int i, j;
    double sum;

    x[n] = b[n]/a[n][n];

    for(i=n-1;i>=1;i--){
        sum = 0;
        for(j=i+1;j<=n;j++)
            sum += a[i][j] * x[j];
        x[i] = (b[i] - sum) / a[i][i];
    }
}

void pivot(int n, int k){
    int i, j, p;
    double big, dummy;

    p = k;
    big = fabs(a[k][k]/s[k]);

    for(i=k+1;i<=n;i++){
        dummy = fabs(a[i][k]/s[i]);
        if(dummy > big){
            big = dummy;
            p = i;
        }
    }

    if(p != k){
        for(j=k;j<=n;j++){
            dummy = a[p][j];
            a[p][j] = a[k][j];
            a[k][j] = dummy;
        }
        dummy = b[p];
        b[p] = b[k];
        b[k] = dummy;
        dummy = s[p];
        s[p] = s[k];
        s[k] = dummy;
    }
}

int eliminate(int n){
    int i, j, k;
    double factor;

    for(k=1;k<=n-1;k++){
        pivot(n, k);
        if(fabs(a[k][k]/s[k]) < eps)
            return -1;
        for(i=k+1;i<=n;i++){
            factor = a[i][k]/a[k][k];
            for(j=k+1;j<=n;j++)
                a[i][j] = a[i][j] - (factor*a[k][j]);
            b[i] = b[i] - factor*b[k];
        }
    }

    if(fabs(a[n][n]/s[n]) < eps) return -1;
    return 1;
}

bool gauss(int n){
    int i, j, er;

    REP(i, n){
        s[i] = fabs(a[i][1]);
        for(j=2;j<=n;j++)
            if(fabs(a[i][j] > s[i]))
                s[i] = fabs(a[i][j]);
    }

    er = eliminate(n);

    if(er != -1)
        substitute(n);

    return er != -1;
}

int main(){

    int i, j, k, n;

    while(printf("n = ?\n")){
        RD(n);

        REP(i, n){
            REP(j, n)
                RD(a[i][j]);
            RD(b[i]);
        }

        if(!gauss(n)) printf("No Solution :P\n");
        else REP(i, n) printf("X[%d] = %lf\n", i, x[i]);
    }

    return 0;
}








/*

3
3 -.1 -.2 7.85
.1 7 -.3 -19.3
.3 -.2 10 71.4
ans
X1 = 3.000000
X2 = -2.500000
X3 = 7.000000

*/








