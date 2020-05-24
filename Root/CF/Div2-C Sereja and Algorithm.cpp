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

#define SZ 100010
const ll inf = 1LL<<28;
const ll mod = 1LL;


int cum[4][SZ];
char arr[SZ];
map <string , int> M;

//%I64d
int main()
{
    M[ "zyx" ] = 1;
    M[ "xzy" ] = 1;
    M[ "yxz" ] = 1;
    int n, m, i, j, k;
    int ss[10];
    string s;

    while(scanf("%s",arr+1) == 1)
    {
        n = strlen(arr+1);

        mem(cum, 0);

        for(i=1; i<=n; i++)
        {
            cum[0][i] = cum[0][i-1];
            cum[1][i] = cum[1][i-1];
            cum[2][i] = cum[2][i-1];

            if(arr[i] == 'x') cum[0][i]++;
            if(arr[i] == 'y') cum[1][i]++;
            if(arr[i] == 'z') cum[2][i]++;
        }

        scanf("%d",&m);

        while(m--)
        {
            scanf("%d %d",&i,&j);

            ss[0] = cum[0][j] - cum[0][i-1];
            ss[1] = cum[1][j] - cum[1][i-1];
            ss[2] = cum[2][j] - cum[2][i-1];

            if(j-i+1 <= 2)
            {
//                s = "";
//                s += arr[i];
//                s += arr[i+1];
//                s += arr[i+2];
//                if(M.find(s) == M.end())
//                    printf("NO\n");
//                else
                    printf("YES\n");
            }

            else
            {
                sort(ss, ss+3);

//                printf("%d %d %d\n",ss[0],ss[1],ss[2]);

                if(ss[2] - ss[0] <= 1 )
                    printf("YES\n");
                else
                    printf("NO\n");
            }
        }
    }


    return 0;
}

















