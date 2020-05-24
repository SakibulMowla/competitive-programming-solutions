///Hint : http://lbv-pc.blogspot.com/search/label/matrix%20exponentiation

#include "stdio.h"
#define SZ 54

typedef long long ll;

const ll mod = 1LL<<32;

ll ncr[SZ][SZ];

void cal_nCr()
{
    int i, j;

    for(i=0; i<51; i++)
        for(j=0; j<=i; j++)
        {
            if(j == 0) ncr[i][j] = 1;
            else if(j == 1) ncr[i][j] = i;
            else ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
        }
}

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
    matrix power = base;
    while(p)
    {
        if((p&1) == 1) xx = matmul(xx, power, n);
        power = matmul(power, power, n);
        p /= 2;
    }
    return xx;
}

void init(ll k)
{
    base = zero;

    ll i, j, l;

    base.x[1][1] = 1;

    j = 0;
    for(i=2; i<=k+2; i++)
        base.x[1][i] = ncr[k][j++];
    for(i=2; i<=k+2; i++)
    {
        l = 0;
        for(j=i; j<=k+2; j++)
            base.x[i][j] = ncr[k-i+2][l++];
    }
}

int main()
{
    cal_nCr();

    ll test=0, t, n, k, ans, i;

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld %lld",&n,&k);

        init(k);
        matrix final = bigmod(base, n-1, k+2);
        ans = 0;

        for(i=1; i<=k+2; i++)
            ans = (ans + final.x[1][i]) % mod;

        printf("Case %lld: %lld\n",++test,ans);
    }

    return 0;
}
