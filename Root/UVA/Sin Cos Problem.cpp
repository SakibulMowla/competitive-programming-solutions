#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;

double a, b;

double f(double theta)
{
    return (a*sin(theta) + b*cos(theta));
}

int main()
{
    int t;
    double lo, hi, m1, m2, val1, val2, ans, x;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf %lf",&a, &b);

        ans = -1e15;

        lo = 0;
        hi = 2.0*acos(-1.0);

        for(int i=0;i<200;i++)
        {
            m1 = (2*lo + hi) / 3;
            m2 = (lo + 2*hi) / 3;

            val1 = f(m1);
            val2 = f(m2);

            if(val1 >= val2)
            {
                if(val1 >= ans)
                {
                    ans = val1;
                    x = m1;
                }
                hi = m2;
            }
            else
            {
                if(val2 > ans)
                {
                    ans = val2;
                    x = m2;
                }
                lo = m1;
            }
        }

        printf("%.2lf %.2lf\n", x, ans);
    }

    return 0;
}










