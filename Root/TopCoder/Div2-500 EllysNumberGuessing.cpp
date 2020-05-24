//ACed

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

#include <bits/stdc++.h>

using namespace  std;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())

typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;

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

#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

set <pii> ms;
map <int , int> mp;

class EllysNumberGuessing {
public:
	int getNumber(vector <int> gues, vector <int> ans) {
        int i, j, k;
        k = sz(gues);
        clr(ms);
        clr(mp);
        for(i=0;i<k;i++){
            ms.insert(MP(gues[i], ans[i]));
        }

        if(sz(ms) == 1) {
            if(gues[0]+ans[0]<=1000000000 && gues[0]-ans[0]>=1)
                return -1;
        }

        k = sz(ms);

        snuke(ms, it){
            if(it->first+it->second <= 1000000000){if(mp.find(it->first+it->second) == mp.end()) mp[it->first+it->second] = 1;
            else mp[it->first+it->second]++;}
            if(it->first-it->second>=1){if(mp.find(it->first-it->second) == mp.end()) mp[it->first-it->second] = 1;
            else mp[it->first-it->second]++;}
        }

        snuke(mp, it){
            if(it->second == k)
                return it->first;
        }

        return -2;
	}
};
