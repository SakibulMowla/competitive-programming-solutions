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
#include <deque>
#include <assert.h>

//#include <bits/stdc++.h>

using namespace  std;

typedef long long ll;

inline void inp( int &n ){
    n=0;
    int ch=getchar_unlocked();int sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
    while(  ch >= '0' && ch <= '9' )
            n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    n=n*sign;
}


#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REP1(i,a,b) for((i)=a;(i)<=(int)(b);(i)++)
#define REP2(i,a,b) for((i)=a;(i)>=(int)(b);(i)--)
#define snuke(c, itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define ssort(a) stable_sort(a.begin(), a.end())

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1E9;
const ll mod = 1LL;

#define SZ 100010

int arr[SZ];
int cum[SZ];
int ans[SZ];
vector <int> v[SZ], tmp[SZ];

int main()
{
    int test = 0, t;

//    scanf("%d", &t);
    inp(t);

    while(t--)
    {
        int n, q;
//        scanf("%d %d", &n, &q);
        inp(n);
        inp(q);

        for(int i = 1; i <= n; i++)
//            scanf("%d", &arr[i]);
            inp(arr[i]);

        for(int i = 1; i <= q; i++)
        {
            int p, q;
//            scanf("%d %d", &p, &q);
            inp(p);
            inp(q);
            v[q].pb(p);
            tmp[q].pb(i);
        }

        cum[0] = 0;
        arr[0] = -1;

        for(int i = 1; i <= n; i++)
        {
            if(arr[i] == arr[i-1])
            {
                cum[i] = cum[i-1];
                cum[i-1]--;
            }
            else
            {
                cum[i] = 1 + cum[i-1];
            }
            if(v[i].size())
            {
                int k = v[i].size();
                for(int j = 0; j < k; j++)
                {
                    ans[ tmp[i][j] ] = cum[i] - cum[ v[i][j] - 1 ];
                }
                v[i].clear();
                tmp[i].clear();
            }
        }

        printf("Case %d:\n", ++test);
        for(int i = 1; i <= q; i++)
            printf("%d\n", ans[i]);
    }

    return 0;
}






