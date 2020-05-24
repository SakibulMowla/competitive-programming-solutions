
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

typedef long long ll;
typedef pair<ll,ll> pii;

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

ll x[] = {0,0,-1,1};//4-way
ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

ll r, c;
ll arr[55][55], dp[55][55], dp2[55][55];

ll solve(ll i,ll j)
{
    if(dp[i][j])
        return dp[i][j];
    ll &ret = dp[i][j];
    ll p, q, u, v, f=1;
    for(p=0; p<4; p++)
    {
        u = i + x[p];
        v = j + y[p];
        if(u < 0 || v < 0 || u>=r || v >= c) continue;
        if(arr[u][v] < arr[i][j])
            ret += solve(u, v), f = 0;

    }
//    printf("%lld %lld %lld\n",i,j,f);
    ret += f;
    return ret;
}


//%I64d
int main()
{
    ll t, test=0, n, m, i, j, k;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&r,&c);
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
                scanf("%lld",&arr[i][j]), dp[i][j] = 0;
        ll u, v, cnt = 0;
        for(i=0; i<r; i++)
            for(j=0; j<c; j++)
            {
                bool f = true;
                for(k=0; k<4; k++)
                {
                    u = i + x[k];
                    v = j + y[k];
                    if(u >=0 && u < r && v >= 0 && v < c)
                    {

                        if(arr[u][v] > arr[i][j])
                            f = 0;
                    }
                }
                if(f)
                cnt += solve(i, j);
//                for(int q=0;q<r;q++)
//                    for(int d=0;d<c;d++)
//                    {
//                        printf("%lld ",dp[q][d]);
//                    }
//                    printf("\n");

            }

        printf("Case #%lld: %lld\n",++test,cnt);
    }

    return 0;
}
