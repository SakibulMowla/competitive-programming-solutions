/*
*  [题意]
*   F(0) = 0; F(1) = 1; F(n) = F(n-1)+F(n-2); （斐波那契数列）
*   设C[i][j]为组合数i种元素中取j种元素的方法
*   给出n、m，求( C[n][0]*F(0)+C[n][1]*F(1)+...+C[n][k]*F(k) ) % m;
*  [解题方法]
*   设矩阵 A  =  |1 1|
*               |1 0|
*   设矩阵 B = (A^n)
*   则B[0][0] = F(n-1); B[0][1] = B[1][0] = F(n); B[1][1] = F(n-1);
*       { 注：上述为斐波那契矩阵的性质 }
*   令D = ( C[n][0]*(A^0) + C[n][1]*(A^1) +...+ C[n][k]*(A^k) ) % m
*       = ( (A + E)^n ) % m   (E为单位阵)
*       { 类比二次多项式(x+1)^n = C[n][0]+C[n][0]*x+...+C[n][k]*(x^k) }
*   则D[1][0]或D[0][1]即为所求
*/


#include "stdio.h"

typedef long long ll;

ll mod;

struct matrix
{
    ll x[3][3];
};

matrix base, zero, ret;

matrix matmul(matrix &a, matrix &b, int n)
{
    int i, j, k;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            ret.x[i][j] = 0;
            for(k=1;k<=n;k++)
                ret.x[i][j] = ret.x[i][j] + (a.x[i][k] * b.x[k][j]) % mod;
            ret.x[i][j] %= mod;
        }
    return ret;
}

matrix power, xx;

matrix bigmod(matrix b, ll p, int n)
{
    xx = zero;
    int i;
    for(i=1;i<=n;i++)
        xx.x[i][i]= 1;
    power = b;
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
    base.x[1][1] = 2;
    base.x[1][2] = base.x[2][1] = base.x[2][2] = 1;

    ll n, t;

    scanf("%I64d",&t);

    while(t--)
    {
        scanf("%I64d %I64d",&n,&mod);
        matrix final = bigmod(base, n, 2);
        printf("%I64d\n",final.x[2][1]);
    }



    return 0;
}
