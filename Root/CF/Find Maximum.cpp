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

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;

ll cum_sum[SZ], cum_nai[SZ];
ll arr[SZ];

//%I64d
int main()
{

    ll i, j, k, n, m, maxim;
    char s[SZ];

    while(scanf("%I64d",&n) == 1)
    {
        for(i=1; i<=n; i++)
        {
            scanf("%I64d",&arr[i]);
        }

        scanf("%s",s+1);

        maxim = 0;

        for(i=1; i<=n; i++)
        {
            if(s[i] == '1')
                maxim += arr[i];

            cum_sum[i] = arr[i] + cum_sum[i-1];

            if(s[i] == '0')
                cum_nai[i] = arr[i] + cum_nai[i-1];
            else
                cum_nai[i] = cum_nai[i-1];
        }

        j = maxim;

        for(i=n; i>=1; i--)
        {
            if(s[i] == '1' && cum_nai[i-1] > arr[i])
                maxim = max(maxim, j-arr[i]+cum_nai[i-1]);
        }

//        printf("yes\n");

        printf("%I64d\n",maxim);
    }


    return 0;
}



