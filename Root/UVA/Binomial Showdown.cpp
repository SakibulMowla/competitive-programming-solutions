#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    unsigned long long n,k,c,b,mul;
    while(scanf("%llu %llu",&n,&k) == 2)
    {
        if(n==0 && k==0)break;
        if(n==k-1 || k==1)
        {
            printf("%llu\n",n);
            continue;
        }
        if(k > n/2)
            k=n-k;
        c=n-k;
        mul=1;
        b=k;
        while(n > c)
        {
            mul*=n;
            --n;
            while(b>1 && mul%b==0)
            {
                mul/=b;
                b--;
            }
        }
        printf("%llu\n",mul);
    }
    return 0;
}
