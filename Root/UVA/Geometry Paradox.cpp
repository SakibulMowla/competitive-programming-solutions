#include "stdio.h"
#include "math.h"

const double pi = 2.0 * acos(0.0);

int main()
{
    int t,len;
    double r,r1,r2,a,a1,a2,ans;
    char arr[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %[^\n]",arr);
        len = sscanf(arr,"%lf %lf",&r1,&r2);
        if(len == 1)
        {
            r2 = r1 / 4;
            r1 = r1 / 4;
        }
        r = r1 + r2;
        a = pi * r * r;
        a1 = pi * r1 * r1;
        a2 = pi * r2 * r2;
        ans = a - (a1 + a2);
        printf("%.4lf\n",ans);
    }

    return 0;
}
