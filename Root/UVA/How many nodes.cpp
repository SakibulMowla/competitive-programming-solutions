            // 10223 - How many nodes ?
//Catalan Numbers Problem
//Formula Co = 1 and C(n+1) = C(n)*(2*(2n+1)/(n+2))
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    long long n,i,arr[30];
    arr[0] = arr[1] = 1;
    for(i=1;i<20;i++)
        arr[i+1] = arr[i] * 2 * (2*i + 1) / (i + 2) ;
    while(scanf("%lld",&n) == 1)
    {
        for(i=1;i<=20;i++)
        {
            if(arr[i] == n)
            {
                printf("%lld\n",i);
                break;
            }
        }
    }

    return 0;
}
