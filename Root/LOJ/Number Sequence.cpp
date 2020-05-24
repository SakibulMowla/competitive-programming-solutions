#include "stdio.h"
using namespace std;

typedef long long ll;
const ll mod = 10000LL;

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
    int test = 0, t, n, m;
    ll a, b, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lld %lld %d %d",&a,&b,&n,&m);
        base.x[1][1] = 1LL;
        base.x[1][2] = 1LL;
        base.x[2][1] = 1LL;
        base.x[2][2] = 0LL;
        if(n == 0)
        {
            ans = kar_mod(a, m);
        }
        else if(n == 1)
        {
            ans = kar_mod(b, m);
        }
        else
        {
            matrix final = bigmod(base, n-1, 2);
            ans = ( (final.x[1][1] * b) % mod + (final.x[1][2] * a) % mod ) % mod;
            ans = kar_mod(ans, m);
        }

        printf("Case %d: %lld\n",++test,ans);
    }

    return 0;
}
