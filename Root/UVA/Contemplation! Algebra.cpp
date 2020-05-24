#include "stdio.h"

typedef long long ll;

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
    char arr[50];
    base.x[2][1] = 1;
    ll p, q, n, ans, m;

    while(~scanf(" %[^\n]",arr))
    {
        m = sscanf(arr,"%lld %lld %lld",&p,&q,&n);
        if(m == 2)
            break;
        if(n == 0)
            printf("2\n");
        else if(n == 1)
            printf("%lld\n",p);
        else
        {
            base.x[1][1] = p, base.x[1][2] = -q;
            matrix final = bigmod(base, n-1, 2);
            ans = final.x[1][1]*p + final.x[1][2]*2;
            printf("%lld\n",ans);
        }
    }

    return 0;
}
