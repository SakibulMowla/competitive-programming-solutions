#include <stdio.h>
#include <string.h>


int main()
{
    int n,a,b,c,count,i,d;
    while(scanf("%d",&n) == 1)
    {
        count = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            d=a+b+c;
            if(d>=2)count++;
        }
        printf("%d\n",count);
    }

    return 0;
}
