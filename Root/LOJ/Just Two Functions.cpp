#include "stdio.h"
using namespace std;

typedef long long ll;
ll mod;

struct matrix
{
    ll x[7][7];
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

ll kar_mod(ll num, int m)
{
    if(m == 1) return num % 10;
    else if(m == 2) return num % 100;
    else if(m == 3) return num % 1000;
    else return num % 10000;
}

int main()
{
    int test = 0, t, q, i, j;
    ll n, m, a1, b1, c1, a2, b2, c2, ff, gg;
    ll f[4], g[4];

    for(i=0;i<=6;i++)
        for(j=0;j<=6;j++)
            base.x[i][j] = 0;

    scanf("%d",&t);

    while(t--)
    {
        printf("Case %d:\n",++test);

        scanf("%lld %lld %lld",&a1,&b1,&c1);
        scanf("%lld %lld %lld",&a2,&b2,&c2);
        scanf("%lld %lld %lld",&f[0],&f[1],&f[2]);
        scanf("%lld %lld %lld",&g[0],&g[1],&g[2]);
        scanf("%lld",&m);
        scanf("%d",&q);

        mod = m;

        base.x[1][1] = a1;
        base.x[1][2] = b1;
        base.x[1][6] = c1;
        base.x[2][1] = 1;
        base.x[3][2] = 1;
        base.x[4][3] = c2;
        base.x[4][4] = a2;
        base.x[4][5] = b2;
        base.x[5][4] = 1;
        base.x[6][5] = 1;


        while(q--)
        {
            scanf("%lld",&n);
            if(n <= 2)
            {
                printf("%lld %lld\n",f[n]%mod,g[n]%mod);
                continue;
            }
            matrix final = bigmod(base, n-2, 6);

            ff = final.x[1][1]*f[2] + final.x[1][2]*f[1] + final.x[1][3]*f[0] +
                 final.x[1][4]*g[2] + final.x[1][5]*g[1] + final.x[1][6]*g[0];
            ff %= mod;
            gg = final.x[4][1]*f[2] + final.x[4][2]*f[1] + final.x[4][3]*f[0] +
                 final.x[4][4]*g[2] + final.x[4][5]*g[1] + final.x[4][6]*g[0];
            gg %= mod;


            printf("%lld %lld\n",ff ,gg);
        }

    }

    return 0;
}
