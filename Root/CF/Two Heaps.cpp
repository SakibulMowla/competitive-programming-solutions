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

#define SZ 1010
const ll inf = 1LL<<28;
const ll mod = 1LL;

set <int> s1, s2;
map <int , int> M;
map <int , int>::iterator it;
int ara[SZ];

struct data
{
    int x, y;
};

data arr[SZ];

//%I64d
int main()
{

    int i, j, k, n;

    while(scanf("%d",&n) == 1)
    {
        for(i=0;i<=100;i++)
            arr[i].x = arr[i].y = 0;

//        mem(pos, 0);
        s1.clear();
        s2.clear();
        M.clear();

        for(i=0; i<2*n; i++)
        {
            scanf("%d",&ara[i]);
            if(M.find(ara[i]) == M.end())
                M[ ara[i] ] = 1;
            else
                M[ ara[i] ]++;
        }

        j = k = 0;

        for(it = M.begin(); it!=M.end(); it++)
        {
            if(it->second > 1)
            {
                if(j < k)
                {
                    s1.insert(it->first);
                    if(it->second/2)
                        s2.insert(it->first);

                    j += (it->second/2) + (it->second%2);
                    k += (it->second/2);

                    arr[ it->first ].x = (it->second/2) + (it->second%2);
                    arr[ it->first ].y = (it->second/2);
                }
                else
                {
                    s2.insert(it->first);
                    if(it->second/2)
                        s1.insert(it->first);

                    k += (it->second/2) + (it->second%2);
                    j += (it->second/2);

                    arr[ it->first ].y = (it->second/2) + (it->second%2);
                    arr[ it->first ].x = (it->second/2);
                }
            }
        }

        for(it = M.begin(); it!=M.end(); it++)
        {
            if(it->second == 1)
            {
                if(j < k)
                {
                    s1.insert(it->first);
                    j++;
                    arr[ it->first ].x = 1;
                }
                else
                {
                    s2.insert(it->first);
                    k++;
                    arr[ it->first ].y = 1;
                }
            }
        }

        printf("%d\n",(int)s1.size()*(int)s2.size());

        for(i=0; i<2*n; i++)
        {
            if(arr[ ara[i] ].x != 0)
                arr[ ara[i] ].x--, printf("1 ");
            else
                arr[ ara[i] ].y--, printf("2 ");

        }

        printf("\n");
    }


    return 0;
}



