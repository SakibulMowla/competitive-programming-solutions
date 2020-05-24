#include "stdio.h"

typedef long long ll;

const ll mod = 1000000009LL;

struct matrix
{
    ll x[4][4];
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
                ret.x[i][j] = ret.x[i][j] +(a.x[i][k] * b.x[k][j]) % mod;
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
    base.x[1][1] = 1, base.x[1][2] = 1, base.x[1][3] = 1;
    base.x[2][1] = 1, base.x[2][2] = 0, base.x[2][3] = 0;
    base.x[3][1] = 0, base.x[3][2] = 1, base.x[3][3] = 0;

    ll n, ans;

    while(scanf("%lld",&n) == 1 && n)
    {
        if(n <= 3)
        {
            printf("%lld\n",n-1);
        }
        else
        {
            matrix final = bigmod(base, n-3, 3);
            ans = (final.x[1][1] * 2) % mod;
            ans = (ans+(final.x[1][2]*1)%mod)%mod;
            ans = (ans+(final.x[1][3]*0)%mod)%mod;
            printf("%lld\n",ans);
        }
    }

    return 0;
}
