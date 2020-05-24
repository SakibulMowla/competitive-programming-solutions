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

typedef long long ll;
typedef pair<ll,ll> pii;

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

#define SZ 1000010
#define SZ1 100010
#define sq(x) ((x)*(x))

const ll inf = 1LL<<28;
const ll mod = 1LL;

bool prime[SZ];
ll arr[SZ1];
ll sszz;
bool segment[SZ];

void sieve()
{
    ll i, j ,k;

    prime[0] = prime[1] = 1;

    for(i=4; i<SZ; i+=2)
        prime[i] = 1;

    k = sqrt(SZ)+1;

    for(i=3; i<=k; i+=2)
        if(!prime[i])
            for(j=i*i; j<SZ; j+=i<<1)
                prime[j] = 1;

    arr[sszz++] = 2;

    for(i=3; i<SZ; i+=2)
        if(!prime[i])
            arr[sszz++] = i;
}


ll segmented_sieve(ll a, ll b)
{
    ll i, cnt = (a<=2 && 2<=b)? 1 : 0;
    ll j, k;

    if(b<2) return 0;
    if(a<3) a = 3;
    if(a%2==0) a++;

    memset(segment, 0, sizeof(bool)*(b-a+2));

    for(i=0; sq(arr[i])<=b; i++)
    {
        j = arr[i] * ( (a+arr[i]-1) / arr[i] );
        if(j%2==0) j += arr[i];
        for(k=arr[i]<<1; j<=b; j+=k)
            if(j!=arr[i])
                segment[j-a] = 1;
    }

    for(i=0; i<=b-a; i+=2)
        if(!segment[i])
            cnt++;

    return cnt;
}

ll nod(ll n)
{
    ll i, j, ans;

    ans = 1LL;

    for(i=0; i<sszz && n!=1 && arr[i]<=n; i++)
    {
        if(n%arr[i] == 0)
        {
            j = 0;
            while(n%arr[i] == 0)
            {
                j++;
                n /= arr[i];
            }
            ans *= (j+1LL);
        }
    }

    if(n != 1)
        ans *= 2LL;

    return ans;
}



int main()
{
    sieve();

    ll t, l, r, i, j, k, ans;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&l,&r);

        ans = 0LL;

        ans = segmented_sieve(l, r);

        k = sqrt(l);
        for(i=k;; i++)
        {
            if(i*i > r) break;
            if(i*i >= l)
            {
                if(prime[ nod(i*i) ] == 0)
                    ans++;
            }
        }

        printf("%lld\n",ans);
    }



    return 0;
}





