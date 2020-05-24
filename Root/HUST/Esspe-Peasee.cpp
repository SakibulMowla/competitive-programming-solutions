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



//%I64d
int main()
{

    ll i, j, k, a, b, x, y, z, ulta, ans;

    while(scanf("%lld %lld %lld",&x,&y,&z) == 3)
    {
        if(x == 0 && y == 0 && z == 0)
            break;
        if(x == 0 && y == 0)
        {
            if(z > 0)
            {
                printf("Unquibable!\n");
            }
            else
            {
                printf("0 fooms and 0 foobs for a twob!\n");
            }
            continue;
        }

        ulta = ans = 0;

        if(x < y)
        {
            swap(x, y);
            ulta = 1;
        }

        if(z % x == 0)
        {
//            printf("%lld %lld %lld xyz\n",x,y,z);
            if(ulta) printf("%lld fooms and %lld foobs for a twob!\n",0LL,z/x);
            else printf("%lld fooms and %lld foobs for a twob!\n",z/x,0LL);
            continue;
        }

        ll rem, koyta1, koyta2;
        ll f = 0;

        koyta1 = z / x;
        rem = z % x;

        ll a, d;

        a = z % x;
        d = x;


        for(i=0;;i++)
        {
            if(rem % y == 0)
            {
                koyta2 = rem / y;
                f = 1;
                break;
            }
            koyta1--;

            ll lo = 1LL,mid,hi=100000000000LL;
            ll val = z - (koyta1*x);

            while(lo+1 < hi)
            {
                mid = (lo + hi) / 2;
                if( (y*mid-a) / d <= val)   lo = mid;
                else hi = mid;
            }

//            rem = z - (koyta1*x);
            rem += lo*y;
            printf("rem = %lld\n",rem);

//            koyta1 -= (x*lo) / y;

            if(koyta1 < 0)
            {
                break;
            }
            if(rem > z)
            {
                break;
            }
        }

        if(f)
        {
            if(ulta) printf("%lld fooms and %lld foobs for a twob!\n",koyta2,koyta1);
            else printf("%lld fooms and %lld foobs for a twob!\n",koyta1,koyta2);
        }

        else printf("Unquibable!\n");
    }


    return 0;
}
