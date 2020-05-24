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

void RD(int &x) {
    scanf("%d",&x);
}
void RD(ll &x) {
    scanf("%I64d",&x);
}
void RD(double &x) {
    scanf("%lf",&x);
}
void RD(int &x,int &y) {
    scanf("%d%d",&x,&y);
}
void RD(ll &x,ll &y) {
    scanf("%I64d%I64d",&x,&y);
}
void RD(double &x,double &y) {
    scanf("%lf%lf",&x,&y);
}
void RD(char *s) {
    scanf("%s",s);
}
void RD(char &s) {
    scanf("%c",&s);
}
void RD(string &s) {
    cin>>s;
}

void PR(int x) {
    printf("%d\n",x);
}
void PR(int x,int y) {
    printf("%d %d\n",x,y);
}
void PR(ll x) {
    printf("%I64d\n",x);
}
void PR(char x) {
    printf("%c\n",x);
}
void PR(char *x) {
    printf("%s\n",x);
}
void PR(string x) {
    cout<<x<<endl;
}

#define read(a) freopen("a", "r", stdin)
#define write(a) freopen("a", "w", stdout)

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
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

#define SZ 2*100010

ll arr[SZ], cap[SZ];

set <ll> mys;
set <ll> :: iterator it;
vector <ll> v;

int main() {
    ll n, m, i, j, k, op, a, b;

    while(scanf("%I64d",&n) == 1) {
        mys.clear();
        REP(i, n) mys.insert(i+1);
        memset(arr, 0, sizeof(ll)*(n+5));
        REP(i, n) RD(cap[i+1]);

        RD(m);

        while(m--) {
            RD(op);
            if(op == 1){
                RD(a, b);
                it = mys.lower_bound(a);
                v.clear();

                while(it != mys.end()){
                    k = (*it);
                    if(k < a){
                        it++;
                        continue;
                    }
//                    PR(k);
                    if(arr[k] + b > cap[k]){
                        b -= cap[k]-arr[k];
                        arr[k] = cap[k];
                        v.pb(k);
                    }
                    else {
                        arr[k] += b;
                        b = 0;
                    }
                    it++;
                    if(b == 0) break;
                }

                k = sz(v);

                REP(i, k) mys.erase(v[i]);
            }
            else {
                RD(a);
                PR(arr[a]);
            }
        }
    }


    return 0;
}
















