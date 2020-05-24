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


int col[SZ];

//%I64d
int main()
{
    int i, j, k, x, y, z, n, m;
    vector <int> v, v1;

    while(scanf("%d %d",&n,&m) == 2)
    {
        mem(col, 0);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            v.clear();
            v1.clear();
            k = 0;
            if(!col[x])
            {
                v.push_back(x);
                k++;
            }
            else
                v1.push_back(x);
            if(!col[y])
            {
                v.push_back(y);
                k++;
            }
            else
                v1.push_back(y);
            if(!col[z])
            {
                v.push_back(z);
                k++;
            }
            else
                v1.push_back(z);

            if(k == 0)
                continue;
            else if(k == 1)
            {
                col[ v[0] ] = 6 - col[ v1[0] ] - col[ v1[1] ];
            }
            else if(k == 2)
            {
                if(col[ v1[0] ] == 1)
                {
                    col[ v[0] ] = 2;
                    col[ v[1] ] = 3;
                }
                if(col[ v1[0] ] == 2)
                {
                    col[ v[0] ] = 1;
                    col[ v[1] ] = 3;
                }
                if(col[ v1[0] ] == 3)
                {
                    col[ v[0] ] = 1;
                    col[ v[1] ] = 2;
                }
            }
            else if(k == 3)
            {
                col[ v[0] ] = 1;
                col[ v[1] ] = 2;
                col[ v[2] ] = 3;
             }
        }

        for(i=1;i<=n;i++)
            printf("%d ",col[i]);
        printf("\n");
    }



    return 0;
}



