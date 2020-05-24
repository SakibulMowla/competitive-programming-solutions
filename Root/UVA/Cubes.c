#include <stdio.h>

int main()
{
    unsigned long long n,x,y,k;
    while(scanf("%llu",&n)==1 && n)
    {
        k=0;
        for(x=2;x<=60;x++)
        {
            for(y=1;y<x;y++)
            {
                if(x*x*x-y*y*y==n)
                {
                    printf("%llu %llu\n",x,y);
                    k=1;
                    break;
                }
            }
            if(k==1) break;
        }
        if(k==0)
            printf("No solution\n");
    }
    return 0;
}
