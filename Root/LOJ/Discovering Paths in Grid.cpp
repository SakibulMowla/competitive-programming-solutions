#include "stdio.h"
#include "vector"
#include "string.h"
#include "map"
#include "iostream"

using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;

struct matrix
{
    ll x[36][36];
};

matrix base, zero;

matrix matmul(matrix &a, matrix &b, int n)
{
    matrix ret;
    int i, j, k;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            ret.x[i][j] = 0;
            for(k=1; k<=n; k++)
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod;
            ret.x[i][j] %= mod;
        }
    return ret;
}

matrix bigmod(matrix b, ll p, int n)
{
    matrix xx = zero;
    int i;
    for(i=1; i<=n; i++)
        xx.x[i][i] = 1;
    matrix power = b;
    while(p)
    {
        if((p&1) == 1) xx = matmul(xx, power, n);
        power = matmul(power, power, n);
        p /= 2;
    }
    return xx;
}

int c1[9], c2[9], c[9];

bool chk(int a, int b)
{
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));
    memset(c, 0, sizeof(c));
    int i, j;
    for(i=0; i<7; i++)
        if(a&(1<<i))
            c1[i+1] = 1;
    for(i=0; i<7; i++)
        if(b&(1<<i))
            c2[i+1] = 1;
    for(i=1;i<=7;i++)
    {
        if(c1[i] == 1)
        {
            if(i-1 >= 1 && c[i-1]==0 && c2[i-1] == 1)
            {
                c[i-1] = 1;
                continue;
            }
            if(i+1 <= 7 && c[i+1]==0 && c2[i+1] == 1)
            {
                c[i+1] = 1;
                continue;
            }
            return false;
        }
    }
    return true;
}

map <int , int> M;

int main()
{
    vector <int> v;
    ll i, j=0;

    for(i=1; i<128; i++)
    {
        if(__builtin_popcount(i) == 4)
            v.push_back(i), M[i] = ++j;
    }

    for(i=0; i<35; i++)
        for(j=0; j<35; j++)
            if(chk(v[i], v[j]))
                base.x[i+1][j+1] = 1;

    ll test = 0, t, ans, n, mask, val;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        mask = 0;

        for(i=0;i<7;i++)
        {
            scanf("%lld",&val);
            if(val)
                mask |= 1<<i;
        }

        matrix final = bigmod(base, n-1, 35);
        val = M[mask];
        ans = 0;

        for(i=1;i<=35;i++)
            ans = (ans + final.x[val][i]) % mod;

        printf("Case %lld: %lld\n",++test,ans);
    }

    return 0;
}
