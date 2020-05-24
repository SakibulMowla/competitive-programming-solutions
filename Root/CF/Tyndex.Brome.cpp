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

typedef long long ll;
typedef pair<int , int> pii;
typedef pair<ll , ll> pll;

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


vector <int> adj[30];

ll b_search(int val, int indx)
{
    int lo, hi, mid;
    ll ans = 1e12;

    lo = 0;
    hi = sz(adj[indx]) - 1;

    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if(adj[indx][mid] == val)
            return 0;
        if(adj[indx][mid] < val)
            lo = mid + 1;
        else
            hi = mid-1;

//        printf("%d %d\n",mid,adj[indx][mid]);

        ans = min(ans, (ll)abs(val-adj[indx][mid]));
    }

    return ans;
}

//%I64d
int main()
{
    int n, k, i, j;
    ll l;

    string s, c;

    while(scanf("%d %d",&n,&k) == 2)
    {
        for(i=0;i<26;i++)
            adj[i].clear();

        cin >> s;

        for(i=0;i<s.length();i++)
        {
            adj[s[i]-'a'].push_back(i);
        }

        while(n--)
        {
            l = 0;

            cin >> c;

            for(i=0;i<c.length();i++)
            {
                if(sz(adj[c[i]-'a']) == 0)
                    l += sz(c);
                else
                    l += b_search(i, c[i]-'a');
            }

            printf("%I64d\n",l);
        }
    }


    return 0;
}

















