/*
A (N) = X * A (N-1) + Y * A (N-2)
S (N) = S (N-1) + A (N) ^ 2;
Merge it
S (N) = S (N-1) + X ^ 2 * A (N-1) ^ 2 + Y ^ 2 * A (N-2) +2 * X * Y * A (N-1) A ( N-2);

Done to a topic like: HDU 1757  f (x) = A0 * f (x-1) + A1 * f (x-2) + A2 * f (x-3) + ...... + A9 * f (x -10);
Then extract the parameters have four: the
                        S (N-1) A (N-1) ^ 2 A (N-2)% ^ 2 A (N-1) A (N-2)
Corresponds to the coefficient 1 X ^ 2 Y ^ 2 2 * X * Y

| 1 X ^ 2 Y ^ 2 2 * X * Y | | S (N-1) |
| 0 X ^ 2 Y ^ 2 2 * X * Y | | A (N-1) ^ 2 |
| 0 1 0 0 | | A (N-2) ^ 2 |
| 0 X 0 Y | | A (N-1) A (N-2) |
*/


#include "stdio.h"

typedef long long ll;

const ll mod = 10007LL;

struct matrix
{
    ll x[5][5];
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
        if(p&1) xx = matmul(xx, power, n);
        power = matmul(power, power, n);
        p /= 2;
    }
    return xx;
}


int main()
{
    base.x[1][1] = 1;
    base.x[3][2] = 1;
    ll n, x, y, ans, i;

    while(scanf("%I64d %I64d %I64d",&n,&x,&y) == 3)
    {
        base.x[1][2] = (x*x) % mod ; base.x[1][3] = (y*y) % mod; base.x[1][4] = (2*x*y) % mod;
        base.x[2][2] = (x*x) % mod ; base.x[2][3] = (y*y) % mod; base.x[2][4] = (2*x*y) % mod;
        base.x[4][2] = x % mod; base.x[4][4] = y % mod;

        matrix final = bigmod(base, n-1, 4);

        ans = 1LL;

        for(i=1;i<=4;i++)
            ans = ( ans + final.x[1][i] ) % mod;

        printf("%I64d\n",ans);
    }

    return 0;
}
