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

#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

#define X first
#define Y second

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
ll BigMod(ll B,ll P,ll M) {
    ll R=1%M;    /// (B^P)%M
    while(P>0) {
        if(P%2==1) {
            R=(R*B)%M;
        }
        P/=2;
        B=(B*B)%M;
    }
    return R;
}

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 10000010
const ll inf = 1LL<<28;
const ll mod = 10007LL;

int cnt[SZ];
bool prime[SZ];

void sieve() {
    ll i, j ,k;

    prime[0] = prime[1] = 1;

    for(i=4; i<SZ; i+=2)
        prime[i] = 1;

    k = sqrt(SZ)+1;

    for(i=3; i<=k; i+=2)
        if(!prime[i])
            for(j=i*i; j<SZ; j+=i<<1)
                prime[j] = 1;

    for(i=1; i<SZ; i++) {
        cnt[i] = cnt[i-1];
        if(prime[i] == 0)
            cnt[i]++;
    }
}

//%I64d
int main() {
    sieve();
    ll test=0, t, i, j, k, n, ans;

//    while(scanf("%d",&n) == 1)
//    {
//        printf("%d\n",cnt[n]);
//    }

    while(scanf("%I64d",&n) == 1) {
        if(n == 1) {
            printf("0\n");
            continue;
        }

        ll nprime= (ll)(cnt[n]-1);

        ans = BigMod(2LL, nprime, mod);

        printf("%I64d\n",ans);

    }


    return 0;
}

















