#include "stdio.h"

typedef long long ll;

ll mod;

struct matrix
{
    ll x[3][3];
};

matrix base, zero;

matrix matmul(matrix &a, matrix &b, int n)
{
    matrix ret;
    int i, j, k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            ret.x[i][j] = 0;
            for(k=1;k<=n;k++)
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod;
            ret.x[i][j] %= mod;
        }
    return ret;
}


matrix bigmod(matrix b, ll p, int n)
{
    matrix xx = zero;
    int i;
    for(i=1;i<=n;i++)
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


int main()
{
    ll n, m;

    base.x[1][1] = 1;
    base.x[1][2] = 1;
    base.x[2][1] = 1;
    base.x[2][2] = 0;

    while(~scanf("%lld %lld",&n,&m))
    {
        mod = 1LL<<m;
        if(n < 2)
        {
            printf("%lld\n",n%mod);
        }
        else
        {
            matrix final = bigmod(base, n, 2);
            printf("%lld\n",final.x[2][1]);
        }
    }
}
