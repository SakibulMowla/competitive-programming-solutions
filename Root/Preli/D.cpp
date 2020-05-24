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
ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1000000007LL;

#define SZ  100000+10+1000

int arr[SZ];
vector <int> prime;

void sieve(){
    int i, j, k;

    k = sqrt(SZ);

    for(i=3; i<=k; i++)
        for(j=i*i; j<SZ; j+= i+i)
            arr[j] = 1;

    prime.pb(2);

    for(i=3; i<SZ; i+=2){
        if(arr[i] == 0)
            prime.pb(i);
    }
}

int cnt[2][SZ];

void factor(int n, int mark){
    int i, j, k;

    k = sz(prime);

    for(i=0; i<k && prime[i]*prime[i] <=n; i++){
        if(n % prime[i] == 0){
            j = 0;
            while(n % prime[i] == 0){
                cnt[mark][ prime[i] ]++;
                n /= prime[i];
            }
        }
    }

    if(n != 1){
        cnt[mark][n]++;
    }

    return;
}

int num[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();

    int test, k, n, x, i, j, t=0;
    ll ans1, ans2;

    scanf("%d",&test);

    while(test--){
        mem(cnt, 0);

        scanf("%d %d",&n,&x);

        j = 0;
        int zero = 0;

        for(i=1; i<=n; i++){
            scanf("%d",&num[i]);
            if(num[i] == 0) j++;
            if(num[i] == x) zero = 1;
        }

        printf("Case %d: ",++t);

        if(j == n){
            printf("1\n");
            continue;
        }
        else if(zero == 1){
            printf("0\n");
            continue;
        }

        for(i=1; i<=n; i++){
            factor(x, 1);
            factor(x-num[i], 0);
        }

        k = sz(prime);

        for(i=0; i<k; i++){
            j = prime[i];
            int p = cnt[0][j];
            int q = cnt[1][j];
            cnt[0][j] -= min(p, q);
            cnt[1][j] -= min(p, q);
        }

        ans1 = ans2 = 1LL;

        for(i=0; i<k; i++){
            j = prime[i];
            if(cnt[0][j]) ans1 = (ans1 * BigMod(j, cnt[0][j], mod)) % mod;
            if(cnt[1][j]) ans2 = (ans2 * BigMod(j, cnt[1][j], mod)) % mod;
        }

        printf("%lld/%lld\n",ans1,ans2);
    }



    return 0;
}













