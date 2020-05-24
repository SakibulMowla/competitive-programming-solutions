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

matrix matadd(matrix &a, matrix &b, int n)
{
    matrix ret;
    int i, j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            ret.x[i][j] = (a.x[i][j] + b.x[i][j]) % mod;
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
        if(p&1) xx = matmul(xx, power, n);
        power = matmul(power, power, n);
        p /= 2;
    }
    return xx;
}

ll K, B;
matrix tmp, tmp1;

matrix solve(ll n)
{
    if(n == 1)
    {
        tmp = bigmod(base, K, 2);
        return tmp;
    }
    if(n&1)
    {
        tmp = solve(n-1);
        tmp1 = bigmod(base, n*K, 2);
        tmp = matadd(tmp, tmp1, 2);
        return tmp;
    }

    tmp = solve(n>>1);
    tmp1 = bigmod(base, (n>>1)*K, 2);

    tmp1 = matmul(tmp1, tmp, 2);
    tmp = matadd(tmp, tmp1, 2);

    return tmp;
}

int main()
{
    base.x[1][1] = base.x[1][2] = base.x[2][1] = 1;

    ll n;

    while(scanf("%I64d %I64d %I64d %I64d",&K,&B,&n,&mod) == 4)
    {
        matrix ans = bigmod(base, B, 2);
        if(n>1)
        {
            matrix tmp = solve(n-1);
            tmp = matmul(ans, tmp, 2);
            ans = matadd(ans, tmp, 2);
        }
        printf("%I64d\n",ans.x[2][1]);
    }

    return 0;
}
