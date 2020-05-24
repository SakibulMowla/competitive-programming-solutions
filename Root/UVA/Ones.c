#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    long long int i,n,sum;
    while(scanf("%lld",&n)==1)
    {
        sum=1;
        for(i=0;;i++)
        {
            sum+=pow(10,i);
            if(sum%n==0)
            {
                printf("%lld",i+1);
                break;
            }
        }
    }
    return 0;
}
