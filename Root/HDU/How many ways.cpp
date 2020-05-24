#include "stdio.h"

typedef long long ll;

const ll mod = 1000LL;

struct matrix
{
    ll x[22][22];
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

int main()
{
    ll n, m, i, j, k, l, t;

    while(scanf("%I64d %I64d",&n,&m) == 2 && (n+m))
    {
        base = zero;
        for(i=0; i<m; i++)
        {
            scanf("%I64d %I64d",&j,&k);
            j++;
            k++;
            base.x[j][k] = 1;
        }
        scanf("%I64d",&t);
        while(t--)
        {
            scanf("%I64d %I64d %I64d",&j,&k,&l);
            j++;
            k++;
            matrix final = bigmod(base, l, n);
            printf("%I64d\n",final.x[j][k]);
        }
    }

    return 0;
}
