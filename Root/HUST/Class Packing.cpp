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

int arr[100];
int cap[] = {20, 20, 20, 25, 25, 30, 30};


//%I64d
int main()
{

    int n, i, j, k, tea, rem, cp;

    while(1)
    {
        k = 0;
        for(i=0; i<=6; i++)
        {
            scanf("%d",&arr[i]);
            if(arr[i] == 0)
                k++;
        }
        if(k == 7)
            break;

        tea = 0;

        for(i=6; i>=1; i--)
        {
            tea += (arr[i]/cap[i]);
            arr[i] = arr[i] % cap[i];

            cp = min(cap[i-1], cap[i]);

//            tea += (arr[i]/cp);
//            arr[i] %= cp;
            if(arr[i] > cp)
            {
                tea++;
                continue;
            }

            rem = cp - arr[i];

            if(arr[i] > 0)
            {
                if(arr[i-1] > rem)
                {
                    arr[i-1] = arr[i-1] - rem;
                    tea++;
                }
                else
                {
                    arr[i-1] = 0;
                    tea++;
                }
            }
        }

//        printf("tea = %d\n",tea);

        tea += (arr[0] / 20) + (bool)(arr[0]%20);

        printf("%d\n",tea);
    }


    return 0;
}

