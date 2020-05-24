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

ll cum[SZ];
ll arr[SZ];


//%I64d
int main()
{

    ll t, n, m, q, i, j, k, range, val1, val2, ans1, ans2, test=0, l, r;

    scanf("%I64dd",&t);

    while(t--)
    {
        scanf("%I64d",&n);

        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&arr[i]);
            cum[i] = arr[i] + cum[i-1];
        }

        scanf("%I64d",&q);

        printf("Case #%d:\n",++test);

        while(q--)
        {
            scanf("%I64d %I64d",&l,&r);
            l++;
            r++;
            range = r-l+1;

            val1 = ceil( (double) (cum[r]-cum[l-1]) / (double) range );
            val2 = floor( (double) (cum[r]-cum[l-1]) / (double) range );

            printf("val %I64d %I64d\n",val1,val2);

            ans1 = (cum[r]-cum[l-1]) - (range*val1);
            ans2 = (cum[r]-cum[l-1]) - (range*val2);

            printf("%I64d\n",min(ans1, ans2));
        }

        printf("\n");
    }


    return 0;
}



