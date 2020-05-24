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

int step(int n)
{
    int val = 0, k = n;
    while(n > 1)
    {
        if(!(n&1))
            n >>= 1;
        else
            n--;
        val++;
    }

//    printf("n val %d %d\n",k,val);

    return val;
}


int gen(int n, int k)
{
    int i, num=0;

    for(i=0;i<35;i++)
    {
        if((n&(1<<i)) && (k&(1<<i))==0)
            num |= 1<<i;
    }

    return num;
}


//int solve(int n)
//{
//    int i, j, k, ans, val;
//
//    k = n;
//
//    if((n&(n-1)) == 0)
//        return step(n>>1);
//
//    ans = 1e9;
//
//    while(k>1)
//    {
////        printf("yes\n");
//        k--;
//        k&=n;
//
////        printf("k = %d\n",k);
//        val = step(k);
////        printf("yes\n");
//        val = max(val, (step( gen(n, k) )) );
//        ans = min(ans, val);
//
////        printf("yes\n");
//    }
//
//    return ans;
//}


int solve(int n)
{
    int i, j, k, hi, lo, m1, m2, ans, val, val2;

    lo = 1, hi = n - 1;
//    ans = max(0, step(n-1));

    j = n/2 + (bool)(n%2);
    int cnt = 1000;
    ans = 1e9;

    while(j > 0 && cnt--)
    {
        val = max( step(j), step(n-j) );
        ans = min(ans, val);
        j--;
    }

    return ans;
}

//%I64d
int main()
{
    int t, i, j, k, n;

    scanf("%d",&t);

//    printf("%d %d\n",step(27), step(28));

    while(t--)
    {
        scanf("%d",&n);

        printf("%d\n",solve(n));
//        printf("%d\n",min(step(n/2), step(n-n/2)));
    }



    return 0;
}



