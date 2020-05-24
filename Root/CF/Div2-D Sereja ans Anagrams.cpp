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

//#include <bits/stdc++.h>

using namespace  std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define pb(a, b) a.push_back(b)
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 2*100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

int a[SZ], b[SZ], c[SZ];
vector <int> ans;
map <int , int> mp;
int bad;

void erase(int r){
    int tmp = --mp[r];
    if(tmp == -1) bad--;
    if(tmp == 0) bad++;
}

void add(int r){
    int tmp = ++mp[r];
    if(tmp == 1) bad--;
    if(tmp == 0) bad++;
}

void solve(int n, int m, int start, int jump){
    if(n < m) return;

    int i;
    REP(i, m) add(c[i]);

    if(bad == 0) pb(ans, start);

    for(i=m;i<n;i++){
        erase(c[i-m]);
        add(c[i]);

        if(bad == 0) pb(ans, start+jump*(i-m+1));
    }

    for(i=n-m;i<n;i++)
        erase(c[i]);
}

//%I64d
int main(){
    int n, m, p, i, j, k;

    while(scanf("%d %d %d",&n,&m,&p) == 3){

        clr(mp);
        clr(ans);
        bad = 0;

        REP(i, n) scanf("%d",&a[i]);
        REP(i, m) scanf("%d",&b[i]);

        REP(i, m) erase(b[i]);

        REP(i, p){
            k = 0;
            for(j=i; j<n; j+=p){
                c[k++] = a[j];
            }
            solve(k, m, i, p);
        }

        ssort(ans);
        k = sz(ans);
        printf("%d\n",k);
        REP(i, k) printf("%d ",ans[i]+1);
        printf("\n");
    }


    return 0;
}

















