#include "stdio.h"

typedef long long ll;

ll mod;

struct matrix
{
    ll x[17][17];
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
    ll d, n, m, i, ans;
    ll f[17];
    for(i=2; i<=15; i++)
        base.x[i][i-1] = 1;
    while(scanf("%lld %lld %lld",&d,&n,&m) && (n+m+d))
    {
        mod = m;
        for(i=1; i<=d; i++)
            scanf("%lld",&base.x[1][i]);
        for(i=1; i<=d; i++)
            scanf("%lld",&f[i]);
        if(n <= d)
        {
            printf("%lld\n",f[n]%mod);
        }
        else
        {
            matrix final = bigmod(base, n-d, d);
            ans = 0;
            for(i=1;i<=d;i++)
                ans = (ans + (final.x[1][i] * f[d-i+1]) % mod ) % mod;
            printf("%lld\n",ans);
        }
    }
}
