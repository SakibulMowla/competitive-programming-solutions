#include "stdio.h"

typedef long long ll;
int mod;

struct matrix
{
    int x[13][13];
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


int main()
{
    int a[12], ans, k, m, i, j;

    for(i=0; i<=10; i++)
        for(j=0; j<=10; j++)
            base.x[i][j] = 0;

    while(scanf("%d %d",&k,&m) != EOF)
    {
        mod = m;
        for(i=1; i<=10; i++)
        {
            scanf("%d",&a[i]);
            base.x[1][i] = a[i];
        }
        for(i=2; i<=10; i++)
            base.x[i][i-1] = 1;
        if(k < 10)
        {
            ans = k % mod;
        }
        else
        {
            matrix final = bigmod(base, k-9, 10);
            ans = 0;

            for(i=1; i<=10; i++)
                ans = (ans + (final.x[1][i] * (10-i)) % mod ) % mod;
        }

        printf("%d\n",ans);
    }

    return 0;
}
