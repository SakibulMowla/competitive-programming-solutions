#include "stdio.h"
#include "string.h"
#include "vector"
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

int c[9], c1[9], c2[9];

bool chk(int a, int b)
{
    memset(c, 0, sizeof(c));
    memset(c1, 0, sizeof(c1));
    memset(c2, 0, sizeof(c2));

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
            if(i-1>=1 && c[i-1] == 0 && c2[i-1] == 1)
            {
                c[i-1] = 1;
                continue;
            }
            if(i+1<=7 && c[i+1] == 0 && c2[i+1] == 1)
            {
                c[i+1] = 1;
                continue;
            }
            return false;
        }
    }

    return true;
}

int main()
{
    map <int , int> M;
    vector <int> v;
    int i, j;

    j = 0;
    for(i=0;i<128;i++)
        if(__builtin_popcount(i) == 4)
            v.push_back(i), M[i] = ++j;

    for(i=0;i<35;i++)
        for(j=0;j<35;j++)
            if(chk(v[i], v[j]))
                base.x[i+1][j+1] = 1;
    int test;
    ll n, val, mask, ans;

    scanf("%d",&test);

    while(test--)
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
        ans = 0;
        val = M[mask];

        for(i=1;i<=35;i++)
            ans = (ans + final.x[val][i]) % mod;

        printf("%lld\n",ans);
    }

    return 0;
}
