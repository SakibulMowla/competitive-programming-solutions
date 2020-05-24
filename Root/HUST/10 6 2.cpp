#include "bits/stdc++.h"
using namespace std;
int main()
{
    int n;
    double w, l, r, red, green;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf", &l);
        w = (3.0*l)/5.0;
        r  =l/5.0;

        red = acos(-1)*r*r;
        green = (l*w) - red;

        printf("%.2lf %.2lf\n", red,green);
    }

    return 0;
}

