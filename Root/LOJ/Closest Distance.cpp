#include "stdio.h"
#include "math.h"
#include "iostream"

using namespace std;

struct data
{
    double x, y;
};

double dist(double px, double py, double qx, double qy)
{
    return (px-qx)*(px-qx) + (py-qy)*(py-qy);
}

int main()
{
    data a, b, c, d;
    int test=0, t;
    double ablox, abhix, cdlox, cdhix, abloy, abhiy, cdloy, cdhiy;
    double abm1x, abm1y, abm2x, abm2y, cdm1x, cdm1y, cdm2x, cdm2y;
    double val1, val2, ans;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);

        ablox = a.x;
        abloy = a.y;
        abhix = b.x;
        abhiy = b.y;

        cdlox = c.x;
        cdloy = c.y;
        cdhix = d.x;
        cdhiy = d.y;

        ans = 1e15;

        for(int i=0; i<100; i++)
        {
            abm1x = (2*ablox + abhix) / 3;
            abm1y = (2*abloy + abhiy) / 3;
            abm2x = (ablox + 2*abhix) / 3;
            abm2y = (abloy + 2*abhiy) / 3;

            cdm1x = (2*cdlox + cdhix) / 3;
            cdm1y = (2*cdloy + cdhiy) / 3;
            cdm2x = (cdlox + 2*cdhix) / 3;
            cdm2y = (cdloy + 2*cdhiy) / 3;

            val1 = dist(abm1x, abm1y, cdm1x, cdm1y);
            val2 = dist(abm2x, abm2y, cdm2x, cdm2y);

            if(val1 <= val2)
            {
                ans = min(ans, val1);
                abhix = abm2x;
                abhiy = abm2y;
                cdhix = cdm2x;
                cdhiy = cdm2y;
            }
            else
            {
                ans = min(ans, val2);
                ablox = abm1x;
                abloy = abm1y;
                cdlox = cdm1x;
                cdloy = cdm1y;
            }
        }

        ans = sqrt(ans);

        printf("Case %d: %.10lf\n",++test, ans);
    }

    return 0;
}










