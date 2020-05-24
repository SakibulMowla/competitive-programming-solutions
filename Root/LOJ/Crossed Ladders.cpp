#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;

int main()
{
    double x, y, c, a, b, r, hi, lo, mid;
    int t=0, test, tmp;

    scanf("%d",&test);

    while(test--)
    {
        scanf("%lf %lf %lf",&x,&y,&c);

        lo = 0.0;
        hi = max(x, y);
        mid = (lo + hi) / 2;
        tmp = 25;

        while(tmp--)
        {
            mid = lo + (hi-lo) / 2;
            a = sqrt( (x*x) - (mid*mid) );
            b = sqrt( (y*y) - (mid*mid) );
            r = (a*b) / (a+b);
            if(c < r) lo = mid;
            else hi = mid;
        }

        printf("Case %d: %.10lf\n",++t,mid);
    }

    return 0;
}
