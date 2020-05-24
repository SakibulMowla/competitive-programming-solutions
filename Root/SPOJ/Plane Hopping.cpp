#include "stdio.h"
#define SZ 52

typedef unsigned long long ll;

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
                ret.x[i][j] = ret.x[i][j] + a.x[i][k] * b.x[k][j];
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
    ll test=0, t, n, k, i, j;

    scanf("%llu",&t);

    while(t--)
    {
        scanf("%llu %llu",&k,&n);

        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                scanf("%llu",&base.x[i][j]);

        matrix final = bigmod(base, k, n);

        printf("Region #%llu:\n",++test);

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(j-1) printf(" ");
                printf("%llu",final.x[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

}
