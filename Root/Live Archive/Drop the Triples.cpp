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

using namespace  std;

typedef long long ll;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back

#define X first
#define Y second

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{int g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll BigMod(ll B,ll P,ll M){     ll R=1%M; while(P>0)      {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} return R;} /// (B^P)%M

//template <class T> T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//ll x[] = {0,0,-1,1};//4-way
//ll y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way

typedef pair<int , int> pii;
typedef pair<ll , ll> pll;
const int inf = 1;
const ll mod = 1LL;

#define SZ  1594323+100

int three[14];
int has[SZ][13];

void pre()
{
    three[0] = 1;
    for(int i = 1; i < 14; i++)
        three[i] = 3 * three[i-1];

    int lim = three[13];
    for(int mask = 0; mask < lim; mask++)
    {
        int nmask = mask;
        for(int i = 0; nmask && i < 13; i++)
        {
            has[mask][i] = nmask % 3;
            nmask /= 3;
        }
    }
}

int dp[SZ];

int solve(int mask)
{
    int &ret = dp[mask];
    if(~ret) return ret;

    ret = 0;
    int nmask = mask;

    for(int i = 0; i < 13; i++) if(has[nmask][i])
    {
        nmask -= three[i];
        for(int j = i; j < 13; j++) if(has[nmask][j])
        {
            nmask -= three[j];
            int lim = min(i + j + 1, 13);

            for(int k = j; k < lim; k++) if(has[nmask][k])
            {
                nmask -= three[k];
                ret = max(ret, 1 + solve(nmask));
                nmask += three[k];
            }
            nmask += three[j];
        }
        nmask += three[i];
    }

    return ret;
}

int main() {
    #if defined JESI
//        freopen("1.txt", "r", stdin);
//        freopen("2.txt", "w", stdout);
    #endif

    pre();
    mem(dp, -1);

    int n;

    while(scanf("%d", &n) == 1 && n)
    {
        int hand[2][13];
        mem(hand, 0);

        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            val--;
            hand[i%2][val]++;
        }

        int player[2] = {0, 0};

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 13; j++)
            {
                player[i] += hand[i][j] / 3;
                hand[i][j] %= 3;
            }

        if(player[0] != player[1])
        {
            printf("%d\n", player[0] > player[1] ? 1 : 2);
            continue;
        }

        int mask[2] = {0, 0};

        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 13; j++)
                mask[i] += hand[i][j] * three[j];

        player[0] = solve(mask[0]);
        player[1] = solve(mask[1]);

        if(player[0] != player[1])
            printf("%d\n", player[0] > player[1] ? 1 : 2);
        else
            printf("0\n");
    }

    return 0;
}


//6
//1 1 3 3 3 2




