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
#include <bitset>


using namespace  std;

typedef long long ll;


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

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
const ll mod = 1e9+7;

#define SZ  100000+10

bool arr[SZ];
vector <int> prime;

void sieve()
{
    int k = sqrt(SZ);
    for(int i = 3; i < k; i += 2)
        if(!arr[i])
            for(int j = i * i; j < SZ; j += i + i)
                arr[j] = 1;
    prime.pb(2);
    for(int i = 3; i < SZ; i += 2)
        if(!arr[i])
            prime.pb(i);
//    for(int i = 0; i < 25; i++)
//        printf("%d\n", prime[i]);
}

map <int , int> mp;

void factorize(int n)
{
    for(int i = 0; i < sz(prime) && prime[i] * prime[i] <= n; i++)
    {
        if(n % prime[i] == 0)
        {
            int j = 0;
            while(n % prime[i] == 0)
            {
                j++;
                n /= prime[i];
            }
            if(mp.find(prime[i]) == mp.end()) mp[ prime[i] ] = j;
            else mp[ prime[i] ] += j;
        }
    }

    if(n != 1)
    {
        if(mp.find(n) == mp.end()) mp[n] = 1;
        else mp[n] += 1;
    }
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    sieve();
    int test = 0, t;

    scanf("%d", &t);

    while(t--)
    {
        clr(mp);

        int n;
        scanf("%d", &n);

        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            factorize(val);
        }

        ll ans = 1LL;
        for(map <int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
//            printf("%d %d\n", it->first, it->second);
            ll tmp = BigMod((ll)it->first, (ll)(it->second)+1LL, mod);
            tmp = (tmp - 1LL + mod) % mod;
            tmp = (tmp * BigMod((ll)it->first-1LL, mod-2LL, mod)) % mod;
//            printf("tmp = %lld\n", tmp);
            ans = (ans * tmp) % mod;
        }

        printf("Case %d: %lld\n", ++test, ans);
    }

    return 0;
}













