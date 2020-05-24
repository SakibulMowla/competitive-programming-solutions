#include <stdio.h>
#include <math.h>

int main()
{
    long long int m,i,c,x,v;

    while(1)
    {
        scanf("%lld %lld",&m,&x);
        if(m==0 && x==0) break;

        if(x==100 || x==0 || m==1)
        {
            printf("Not found\n");
            continue;
        }

        v=(100*(m-1))/(100-x);
        c=(100*(m-1))%(100-x);
        if(c==0)
        v--;
        if(v >= m)
            printf("%lld\n",v);
        else
            printf("Not found\n");
    }

    return 0;
}
