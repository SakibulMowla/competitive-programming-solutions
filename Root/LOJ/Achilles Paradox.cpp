#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int t,test;
    double r,l,d;
    t = 0;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lf %lf %lf",&r,&l,&d);
        l += d/r;
        if(d >= l) printf("Case %d: yes\n",++t);
        else printf("Case %d: no\n",++t);
    }

    return 0;
}
