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

template <class T> T gcd(T a, T b){while(b == 0) return a;return gcd(b,a%b);}
template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

#define SZ 1010
#define  X first
#define  Y second
const ll inf = 1LL<<28;
const ll mod = 1LL;

pii a, b;
ll mn1, mn2, mv1, mv2;

bool lesss(pii aa,int mv)
{
    return aa.first <= mv * aa.second;
}

void print(pii aa,int x,int mv)
{
    aa.X = x*aa.Y - aa.X;
    aa.X *= mv;
    ll g = gcd(aa.X, aa.Y*mn1*mn2);
    printf("%I64d/%I64d\n",aa.X/g,(aa.Y*mn1*mn2)/g);
}

bool great(pii aa,int m1,pii bb,int m2)
{
    aa.X *= m1;
    bb.X *= m2;

    return (aa.X*bb.Y) >= (bb.X*aa.Y);
}

//%I64d
int main()
{
    while(cin >> mn1 >> mn2 >> mv1 >> mv2)
    {
        a.X = mn1 * mv2;
        a.Y = mv1;
        b.X = mv1 * mn2;
        b.Y = mv2;

        if(!lesss(a, mn2))
        {
            print(b, mn1, mn2);
            return 0;
        }

        if(!lesss(b , mn1))
        {
            print(a, mn2, mn1);
            return 0;
        }

        if(great(a, mn2, b, mn1))
        {
            print(a, mn2, mn1);
            return 0;
        }

        else
        {
            print(b, mn1, mn2);
            return 0;
        }
    }

    return 0;
}
