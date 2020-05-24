#include "stdio.h"
using namespace std;

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

    base.x[1][2] = 0LL;
    base.x[1][4] = 1LL;
    base.x[2][1] = 1LL;
    base.x[2][2] = 0LL;
    base.x[2][3] = 0LL;
    base.x[2][4] = 0LL;
    base.x[3][1] = 0LL;
    base.x[3][2] = 1LL;
    base.x[3][3] = 0LL;
    base.x[3][4] = 0LL;
    base.x[4][1] = 0LL;
    base.x[4][2] = 0LL;
    base.x[4][3] = 0LL;
    base.x[4][4] = 1LL;

    int test = 0, t, n, m;
    ll a, b, c, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d %lld %lld %lld",&n,&a,&b,&c);

        if(n <= 2)
        {
            ans = 0LL;
        }
        else
        {
            base.x[1][1] = a;
            base.x[1][3] = b;
            matrix final = bigmod(base, n-2, 4);
            ans = (c * final.x[1][4]) % mod;
        }

        printf("Case %d: %lld\n",++test,ans);
    }

    return 0;
}

