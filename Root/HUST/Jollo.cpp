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



//%I64d
int main()
{
    int i, j, k, n, m, tot;
    int a[4], b[4];
    int col[100];

    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&b[0],&b[1]) == 5)
    {
        memset(col, 0, sizeof(col));

        if(a[0] == 0 && a[1] == 0 && a[2] == 0 && b[0] == 0 && b[1] == 0) break;

        col[a[0]] = 1;
        col[a[1]] = 1;
        col[a[2]] = 1;
        col[b[0]] = 1;
        col[b[1]] = 1;

        int f = 0;

        string s1, s2;

        for(i=1; i<=52; i++)
        {
            if(col[i]) continue;

            b[2] = i;

            s1 = "012";
            j = 0;
            tot = 0;

            do
            {
                s2 = "012";
                do
                {
                    k = 0;
                    if(b[ s1[0]-'0' ] > a[ s2[0]-'0' ]) k++;
                    if(b[ s1[1]-'0' ] > a[ s2[1]-'0' ]) k++;
                    if(b[ s1[2]-'0' ] > a[ s2[2]-'0' ]) k++;
                    if(k >= 2) j++;
                }
                while(next_permutation(s2.begin(), s2.end()));
            }
            while(next_permutation(s1.begin(), s1.end()));

            if(j == 36)
            {
                f = 1;
                break;
            }
        }

        if(f) printf("%d\n",i);
        else printf("-1\n");
    }

    return 0;
}

