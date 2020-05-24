#include "stdio.h"
#include "iostream"

using namespace std;

typedef long long ll;

const ll mod = 1000000007LL;

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
        if((p&1)==1) xx = matmul(xx, power, n);
        power = matmul(power, power, n);
        p /= 2;
    }
    return xx;
}


matrix solve(ll n)
{
    if(n == 1LL)
        return base;

    matrix tmp, tmp1;

    if(n&1)
    {
        tmp = solve(n-1);
        tmp1 = bigmod(base, n, 2);
        tmp = matadd(tmp, tmp1, 2);
        return tmp;
    }

    tmp = solve(n/2);
    tmp1 = bigmod(base, n/2, 2);

    tmp1 = matmul(tmp, tmp1, 2);
    tmp = matadd(tmp, tmp1, 2);

    return tmp;
}

int main()
{
    matrix final;
    ll t, n, m, ans, tmp;

    base.x[1][1] = base.x[1][2] = base.x[2][1] = 1;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&m);

        if(m <= 1)
            ans = m;
        else
        {
            final = solve(m);
            ans = final.x[2][1];
        }
        if(n <= 2)
            tmp = max(n-1, 0LL);
        else
        {
            final = solve(n-1);
            tmp = final.x[2][1];
        }

        ans = (ans - tmp + mod) % mod;

        printf("%lld\n",ans);
    }

    return 0;
}
