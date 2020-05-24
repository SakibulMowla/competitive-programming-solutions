#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;

struct data
{
    double x, y, z;
};

double dist(data p, data q)
{
    return ( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) + (p.z-q.z)*(p.z-q.z) );
}

int main()
{
    data a, b, p;

    int test=0, t;
    data m1, m2, hi, lo;
    double val1, val2, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.z,&b.x,&b.y,&b.z,&p.x,&p.y,&p.z);

        lo = a;
        hi = b;
        ans = 1e15;

        for(int i=0;i<100;i++)
        {
            m1.x = (2*lo.x + hi.x) / 3;
            m1.y = (2*lo.y + hi.y) / 3;
            m1.z = (2*lo.z + hi.z) / 3;

            m2.x = (lo.x + 2*hi.x) / 3;
            m2.y = (lo.y + 2*hi.y) / 3;
            m2.z = (lo.z + 2*hi.z) / 3;

            val1 = dist(m1, p);
            val2 = dist(m2, p);

            if(val1 <= val2)
            {
                ans = min(ans, val1);
                hi = m2;
            }
            else
            {
                ans = min(ans, val2);
                lo = m1;
            }
        }

        ans = sqrt(ans);

        printf("Case %d: %.10lf\n",++test, ans);
    }


    return 0;
}








