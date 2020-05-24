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
typedef unsigned long long ull;

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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;


ll f(ll n)
{
    if(n == 1) return 1LL;
    return 1LL + f( (ll)__builtin_popcount(n) );
}

ll ones[70];

ll mark;
ll lim;
ll dp[70][3][70];
string s;
ll solve(ll indx, int flag, ll cnt)
{
    if(indx == -1)
    {
        if(cnt == 0)
        {
            return 1LL;
        }
        return 0LL;
    }
    if(cnt<0) return 0LL;
    ll &ret = dp[indx][flag][cnt];

    if(ret != -1) return ret;
    ret = 0;

    int i, new_flag;
    int en = flag == 0 ? 1 : (lim>>indx)%2LL;
    for(i=0;i<=en;i++)
    {
        if(i == en && flag == 1)
            new_flag = 1;
        else
            new_flag = 0;
        ret += solve(indx-1, new_flag, cnt-i);
    }

    return ret;

}


//%I64d
int main()
{
//freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll i, n, lo, hi, k, res;
    for(i=64;i>=1;i--)
    {
        ones[i] = f(i)-1;
    }

    while(scanf("%lld %lld %lld",&lo,&hi,&k) == 3 && (lo||hi||k))
    {
        if(k == 0)
        {
            if(lo==1)
            printf("1\n");
            else
            printf("0\n");
            continue;
        }

        res = 0LL;

        if(hi <= 64)
        {
            for(i=lo;i<=hi;i++)
                if(ones[i] == k)
                    res++;
            printf("%lld\n",res);
            continue;
        }

        lim = hi;

        for(i=63;i>=1;i--)
        {
            if(ones[i] == k-1)
            {
                mem(dp, -1);
                res += solve(63, 1, i);
            }
        }

        lim = lo - 1;
        for(i=63;i>=1;i--)
        {
            if(ones[i] == k-1)
            {
                mem(dp, -1);
                res -= solve(63, 1, i);
            }
        }
        if(lo==1&&k==1) res--;
        printf("%lld\n",res);
    }
    return 0;
}



