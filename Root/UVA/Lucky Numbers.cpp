#include <stdio.h>
#include <math.h>
int main()
{
    int t,test,n,i,x,s,start;
    scanf("%d",&test);
    for(t=1;t<=test;t++)
    {
        scanf("%d",&n);
        printf("Case %d:",t);
        start = sqrt(n-1);
        for(i=start;i>=1;i--)
        {
            s = i * i;
            x = n - s;
            if(x % i == 0) printf(" %d",x);
        }
        printf("\n");
    }

    return 0;
}
