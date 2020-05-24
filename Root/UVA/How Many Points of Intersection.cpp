// need to take two lines (4 points ; 2 from a , 2 from b) to mahe an intersection
// so the equation is : aC2 * bC2 = a(a-1)/2 * b(b-1)/2 = a*b*(a-1)*(b-1)/4

#include "stdio.h"
#include "math.h"

int main()
{
    long long int a,b,test=0;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        if(a==0 && b==0)
            break;
        printf("Case %lld: %lld\n",++test,a*b*(a-1)*(b-1)/4);
    }

    return 0;
}
