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

ll w[SZ];
ll cum[SZ];


//%I64d
int main()
{
    ll i, j, k, n, l, r, ql, qr, maxim, p1, p2, q;

    while(scanf("%I64d",&n) == 1)
    {
        scanf("%I64d %I64d %I64d %I64d",&l,&r,&ql,&qr);

        for(i=1; i<=n; i++)
        {
            scanf("%I64d",&w[i]);
            cum[i] = cum[i-1] + w[i];
        }

        maxim = 1e14;

        for(i=0; i<=n; i++)
        {
            j = cum[i] * l;
            k = (cum[n] - cum[i]) * r;

            p1 = i;
            p2 = n-i;
            q = 0LL;



            if(abs(p1-p2) > 1)
            {
                if(p1 > p2)
                {
                    q = p1-p2-1;
                    q *= ql;
                }
                else
                {
                    q = p2-p1-1;
                    q *= qr;
                }
            }

            maxim = min(maxim, j+k+q);
        }

        printf("%I64d\n",maxim);
    }



    return 0;
}


