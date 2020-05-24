//#include "stdio.h"
//#include "string.h"
//#include "string"
//#include "stdlib.h"
//#include "math.h"
//#include "map"
//#include "vector"
//#include "queue"
//#include "stack"
//#include "set"
//#include "iostream"
//#include "algorithm"

#include <bits/stdc++.h>

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

#define SZ 300010
const ll inf = 1e17;
const ll mod = 1LL;

ll arr[SZ], cumu[SZ];
map <ll , ll>M1;
map <ll , ll>M2;
vector <ll> tmp;

//%I64d
int main()
{
    ll n, i, j, k, best, besti, bestj, sum;

    while(cin >> n)
    {
        M1.clear();
        M2.clear();
        tmp.clear();

        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&arr[i]);
            if(arr[i] > 0)
                cumu[i] = cumu[i-1] + arr[i];
            else
                cumu[i] = cumu[i-1];
            if(M1.find(arr[i]) == M1.end())
                M1[arr[i]] = i;
        }

        for(i=n;i>=1;i--)
        {
            if(M2.find(arr[i]) == M2.end())
                M2[arr[i]] = i;
        }

        best = -inf;

        for(i=1;i<=n;i++)
        {
            if(M1.find(arr[i]) != M1.end() && M2.find(arr[i]) != M2.end() && M1[arr[i]] != M2[arr[i]])
            {
                j = M2[arr[i]];
                sum = cumu[j] - cumu[i-1];
                if(arr[j] < 0)
                    sum += arr[i] + arr[j];
                if(sum > best)
                {
                    best = sum;
                    besti = i;
                    bestj = j;
                }
            }
        }

        for(i=1;i<=n;i++)
        {
            if(i == besti || i == bestj)    continue;
            if(i < besti || i > bestj) tmp.push_back(i);
            else if(arr[i] <= 0) tmp.push_back(i);
        }

        printf("%I64d %I64d\n",best,(ll)tmp.size());
        k = sz(tmp);
        for(i=0;i<k;i++)
            printf("%I64d ",tmp[i]);
        printf("\n");
    }

    return 0;
}
