#include "stdio.h"

int mod, dim;

struct matrix
{
    int x[32][32];
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

matrix bigmod(matrix b, int p, int n)
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


matrix solve(int n)
{
    if(n == 1)
        return base;

    matrix tmp, tmp1;

    if(n & 1)
    {
        tmp = solve(n-1);
        tmp1 = bigmod(base, n, dim);
        return matadd(tmp, tmp1, dim);
    }

    tmp = solve(n>>1);
    tmp1 = bigmod(base, n>>1, dim);

    tmp1 = matmul(tmp, tmp1, dim);
    tmp = matadd(tmp, tmp1, dim);

    return tmp;
}


int main()
{
    int n, k, i, j;

    scanf("%d %d %d",&n,&k,&mod);

    dim = n;

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            scanf("%d",&base.x[i][j]), base.x[i][j] %= mod;

    matrix final = solve(k);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(j-1) printf(" ");
            printf("%d",final.x[i][j]);
        }
        printf("\n");
    }

    return 0;
}

