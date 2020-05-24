#include "stdio.h"
#include "string.h"
#include "math.h"
#include "stdlib.h"

int main()
{
    double n,m,a;
    scanf("%lf %lf %lf",&n,&m,&a);
    printf("%.0lf\n",ceil(n/a)*ceil(m/a));

    return 0;
}
