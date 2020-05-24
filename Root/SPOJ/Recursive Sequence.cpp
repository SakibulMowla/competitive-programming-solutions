#include "stdio.h"
#define SZ 12

typedef long long ll;

const ll mod = 1e9;

struct matrix
{
    ll x[SZ][SZ];
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
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]);
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
    ll t, i, j, k, n, ans;
    ll b[SZ], c[SZ];

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);

        base = zero;

        for(i=1;i<=n;i++)
            scanf("%lld",&b[i]);
        for(i=1;i<=n;i++)
            scanf("%lld",&base.x[1][i]);

        scanf("%lld",&k);

        if(k <= n)
        {
            printf("%lld\n",b[k]%mod);
            continue;
        }

        for(i=2;i<=n;i++)
            base.x[i][i-1] = 1;

        matrix final = bigmod(base, k-n, n);

        ans = 0;

        for(i=1;i<=n;i++)
            ans = (ans + final.x[1][i] * b[n-i+1]) % mod;

        printf("%lld\n",ans);
    }

    return 0;
}
