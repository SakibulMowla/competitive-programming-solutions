#include "stdio.h"

typedef unsigned long long ll;

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
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]);
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
    ll test = 0, t, p, q, n, ans;

    scanf("%llu",&t);

    while(t--)
    {
        scanf("%llu %llu %llu",&p,&q,&n);

        base.x[1][1] = p;
        base.x[1][2] = -q;
        base.x[2][1] = 1LL;
        base.x[2][2] = 0LL;

        if(n == 0)
            ans = 2;
        else if(n == 1)
            ans = p;
        else
        {
            matrix final = bigmod(base, n-1, 2);
            ans = final.x[1][1] * p + final.x[1][2] * 2;
            printf("%llu %llu\n",final.x[1][1],final.x[1][2]);
        }

        printf("Case %llu: %llu\n",++test,ans);
    }

    return 0;
}

