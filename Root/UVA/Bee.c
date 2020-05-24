#include<stdio.h>

int main()
{
    long long int n,i,j,fn,fn1,fn2;
    while(scanf("%lld",&n)==1)
    {
        if(n<0)
            break;
        else if(n==0)
            printf("0 1\n");
        else if(n==1)
            printf("1 2\n");
        else if(n==2)
            printf("2 4\n");
        else if(n>=3)
        {
            fn1=4;fn2=2;
            for(i=3;i<=n;i++)
            {
                fn=fn1+fn2+1;
                fn2=fn1;
                fn1=fn;
            }
            printf("%lld %lld\n",fn2,fn);
        }
    }
    return 0;
}
