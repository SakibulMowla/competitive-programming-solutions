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

#define X first
#define Y second

#define eps 1e-8

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
typedef pair<double , double> pdd;

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


double dist(double a, double b, double c, double d)
{
    return ( ((a-c)*(a-c)) + ((b-d)*(b-d)) );
}

//%I64d
int main()
{

    pdd a, b, c, d;

    double ab, ac, ad, bad, bcd, cx, cy, mx;
    int test=0, t, i, j, k, cc;
    int f[10];

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf %lf",&a.X,&a.Y);
        scanf("%lf %lf",&b.X,&b.Y);
        scanf("%lf %lf",&c.X,&c.Y);
        scanf("%lf %lf",&d.X,&d.Y);

        ab = dist(a.X, a.Y, b.X, b.Y);
        ac = dist(a.X, a.Y, c.X, c.Y);
        ad = dist(a.X, a.Y, d.X, d.Y);

        if(ab > ac && ab > ad)
        {
            mx = ab;
            f[1] = f[2] = 1;
            f[3] = f[4] = 2;
        }

        else if(ac > ab && ac > ad)
        {
            mx = ac;
            f[1] = f[3] = 1;
            f[2] = f[4] = 2;
        }

        else
        {
            mx = ad;
            f[1] = f[4] = 1;
            f[2] = f[3] = 2;
        }

        bad = bcd = 0;

        for(i=2;i<=4;i++)
        {
            if(f[i] == f[1])
                continue;
            if(i == 2)
                bad += ab;
            else if(i == 3)
                bad += ac;
            else if(i == 4)
                bad += ad;
        }

        for(i=2;i<=4;i++)
        {
            if(f[i] == 1)
            {
                cc = i;
                if(i == 2)
                    cx = b.X, cy = b.Y;
                else if(i == 3)
                    cx = c.X, cy = c.Y;
                else if(i == 4)
                    cx = d.X, cy = d.Y;

                break;
            }
        }

        for(i=2;i<=4;i++)
        {
            if(f[i] == 1)
                continue;
            if(i == 2)
                bcd += dist(cx, cy, b.X, b.Y);
            else if(i == 3)
                bcd += dist(cx, cy, c.X, c.Y);
            else if(i == 4)
                bcd += dist(cx, cy, d.X, d.Y);
        }

        printf("c = %d max = %.0lf bad+bcd = %.0lf\n", cc, mx, bad+bcd);

        if( fabs((bad + bcd) - (2.0*mx)) <= eps)
            printf("yes\n");
        else
            printf("no\n");
    }


    return 0;
}

















