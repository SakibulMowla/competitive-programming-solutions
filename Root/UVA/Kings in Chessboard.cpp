#include "stdio.h"
#include "vector"
#include "iostream"
using namespace std;

typedef long long ll;

const ll mod = (1LL<<32);

struct data
{
    int x, y;
};

struct matrix
{
    ll x[37][37];
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

bool chk(int a, int b)
{
    if(a == b || a+1 == b || a-1 == b)
        return true;
    return false;
}

int main()
{
    ll i, j, test=0, t, n;

    vector <data> v;
    data u, p;

    for(i=1; i<=10; i++)
        for(j=i+2; j<=10; j++)
        {
            u.x = i;
            u.y = j;
            v.push_back(u);
        }
    for(i=0; i<36; i++)
        for(j=0; j<36; j++)
        {
            u = v[i];
            p = v[j];
            if(chk(u.x, p.x) || chk(u.x, p.y) || chk(u.y, p.x) || chk(u.y, p.y))
                continue;
            base.x[i+1][j+1] = 1;
        }

    scanf("%lld",&t);

    while(t--)
    {
        scanf("%lld",&n);
        matrix final = bigmod(base, n-1, 36);
        n = 0;
        for(i=1;i<=36;i++)
            for(j=1;j<=36;j++)
                n = (n + final.x[i][j])%mod;
        printf("Case %lld: %lld\n",++test,n);
    }

    return 0;
}
