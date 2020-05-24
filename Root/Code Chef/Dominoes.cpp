#include "stdio.h"
#include "math.h"
typedef long long ll;

const double mod = 1000000007;
const double phi = 1.618033988750;
const double mphi = 0.618033988750;
const double expo = 1e-8;

double bigmod(double a,double b)
{
    if(b == 0) return (double)1;
    double x = bigmod(a,(long long)b/2);
    x = fmod(x*x,mod);
    if(fmod(b,2) == 1) x = fmod(x*a,mod);
    return x;
}

int main()
{
    ll t;
    double n,a,b,ans;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lf",&n);
        a = bigmod(phi,n) / sqrt(5);
        b = bigmod(mphi,n) / sqrt(5);
        if(fmod(n,2) == 1) b *= -1;
        ans = fmod(a - b + expo,mod);
        printf("%lld\n",(long long)ans);
    }

    return 0;
}
