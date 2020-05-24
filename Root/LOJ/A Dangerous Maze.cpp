#include "stdio.h"

int GCD(int a,int b)
{
    if(b == 0) return a;
    return GCD(b , a%b);
}

int main()
{
    int test=0,t,n,i,j,E,neg,sum;

    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);

        neg = sum = 0;

        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            if(j < 0) neg++ , sum += (-j);
            else sum += j;
        }

        if(neg == n)
        {
            printf("Case %d: inf\n",++test);
            continue;
        }

        E = n - neg;

        j = GCD(E , sum);

        printf("Case %d: %d/%d\n",++test,sum/j,E/j);
    }

    return 0;
}
