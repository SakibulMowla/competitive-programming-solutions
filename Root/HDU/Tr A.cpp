#include "stdio.h"

typedef long long ll;

const ll mod = 9973LL;

struct matrix
{
    ll x[12][12];
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
    ll t, n, k, i, j, ans;

    scanf("%I64d",&t);

    while(t--)
    {
        scanf("%I64d %I64d",&n,&k);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%I64d",&base.x[i][j]);
        matrix final = bigmod(base, k, n);
        ans = 0;
        for(i=1;i<=n;i++)
            ans = (ans + final.x[i][i]) % mod;
        printf("%I64d\n",ans);
    }

    return 0;
}
