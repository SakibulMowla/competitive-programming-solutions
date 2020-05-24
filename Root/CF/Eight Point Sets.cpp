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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

map <ll , ll > M1, M2;
map <ll , ll > ::iterator it;
map <pii , ll> PM;

//%I64d
int main()
{
    ll n, i, j, k;
    vector <ll> v1;
    vector <ll> v2;

//    while(1)
    {
        M1.clear();
        M2.clear();
        PM.clear();
        v1.clear();
        v2.clear();
        for(i=0; i<8; i++)
        {
            scanf("%I64d %I64d",&j,&k);
            M1[j] = 1;
            M2[k] = 1;
            PM[MP(j,k)] = 1;
        }
        k = 0;
        if(sz(M1) == 3 && sz(M2) == 3)
        {
            for(it=M1.begin(); it!=M1.end(); it++)
            {
                v1.push_back(it->first);
            }
            for(it=M2.begin(); it!=M2.end(); it++)
            {
                v2.push_back(it->first);
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            k = 1;
        }
        if(k)
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i == 1 && j == 1)
                {
                    if(PM.find(MP(v1[i], v2[j])) != PM.end())
                    {
                        k = 0;
                        goto here;
                    }
                }
                else
                {
                    if(PM.find(MP(v1[i], v2[j])) == PM.end())
                    {
                        k = 0;
                        goto here;
                    }
                }
            }
        }
        here:;
        if(k) printf("respectable\n");
        else printf("ugly\n");
    }

    return 0;
}
